#include <getopt.h>
#include <math.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include "cachelab.h"

const int MAX_CMD_SIZE = 30;

// Cache line
typedef struct {
  int valid_;
  int tag_;
  // LRU 策略
  int count_;
} CacheLine;

typedef CacheLine *Cache;

// 记录次数
int hit_cnt;
int miss_cnt;
int evict_cnt;

void PrintUsageInfo();
void Load(Cache cache, int set_len, int line_len, int block_len, int verbose, int address, int cnt);

int main(int argc, char **argv) {
  int s = 0;
  int e = 0;
  int b = 0;
  char *t = NULL;
  // 是否输出 trace（verbose）
  int verbose = 0;
  int opt;
  while (-1 != (opt = getopt(argc, argv, "hvs:E:b:t:"))) {
    switch (opt) {
      case 's': {
        s = atoi(optarg);
        break;
      }
      case 'E': {
        e = atoi(optarg);
        break;
      }
      case 'b': {
        b = atoi(optarg);
        break;
      }
      case 'v': {
        // 打印 trace info
        verbose = 1;
        break;
      }
      case 't': {
        t = malloc(strlen(optarg));
        strcpy(t, optarg);
        break;
      }
      case 'h':
      default: {
        PrintUsageInfo();
        break;
      }
    }
  }

  int set_num = 1 << s;
  int line_num = e;

  // cache
  // 这里是一个二维数组，row 为 set index，col 为 line index
  Cache cache = malloc(set_num * line_num * sizeof(CacheLine));
  memset(cache, 0, set_num * line_num * sizeof(CacheLine));

  // 读取 t 中的 cmd
  char cmd[MAX_CMD_SIZE * sizeof(char)];
  memset(cmd, 0, MAX_CMD_SIZE * sizeof(char));
  FILE *fpr = fopen(t, "r");
  int cnt = 0;
  while (fgets(cmd, MAX_CMD_SIZE, fpr)) {
    cnt++;
    // 忽略 I
    if (cmd[0] == 'I') {
      continue;
    }

    char op;
    unsigned address;
    int size;
    sscanf(cmd, " %c %x,%d", &op, &address, &size);
    if (verbose) {
      printf("%c %x,%d", op, address, size);
    }
    if (op == 'M') {
      Load(cache, s, e, b, verbose, address, cnt);
    }
    Load(cache, s, e, b, verbose, address, cnt);
    printf("\n");
  }

  fclose(fpr);
  free(t);
  free(cache);
  printSummary(hit_cnt, miss_cnt, evict_cnt);
  return 0;
}

void Load(Cache cache, int set_len, int line_len, int block_len, int verbose, int address,
          int cnt) {
  address >>= block_len;
  int set_index = address & ((1 << set_len) - 1);
  address >>= set_len;
  int tag = address;
  address >>= line_len;

  int line_num = line_len;

  // 寻找是否存在 tag 相符的 cache line
  // 在该 set 中寻找
  int min_count = __INT_MAX__;
  int idx = -1;
  for (int i = set_index * line_num; i < (set_index + 1) * line_num; i++) {
    CacheLine *cache_line = cache + i;
    if (!cache_line->valid_) {
      min_count = -__INT_MAX__;
      idx = i;
      continue;
    }
    // hit
    if (cache_line->tag_ == tag) {
      if (verbose) {
        printf(" hit");
      }
      hit_cnt++;
      cache_line->count_ = cnt;
      cache_line->tag_ = tag;
      return;
    }
    if (min_count > cache_line->count_) {
      min_count = cache_line->count_;
      idx = i;
    }
  }
  // miss
  if (verbose) {
    printf(" miss");
  }
  miss_cnt++;

  CacheLine *cache_line = cache + idx;
  // 如果 valid，则 evict
  if (cache_line->valid_) {
    if (verbose) {
      printf(" eviction");
    }
    evict_cnt++;
  }

  cache_line->valid_ = 1;
  cache_line->count_ = cnt;
  cache_line->tag_ = tag;
}

void PrintUsageInfo() {
  printf(
      "Usage: ./csim-ref [-hv] -s <num> -E <num> -b <num> -t <file>\n"
      "Options:\n"
      "  -h         Print this help message.\n"
      "  -v         Optional verbose flag.\n"
      "  -s <num>   Number of set index bits.\n"
      "  -E <num>   Number of lines per set.\n"
      "  -b <num>   Number of block offset bits.\n"
      "  -t <file>  Trace file.\n\n"
      "Examples:\n"
      "  linux>  ./csim-ref -s 4 -E 1 -b 4 -t traces/yi.trace\n"
      "  linux>  ./csim-ref -v -s 8 -E 2 -b 4 -t traces/yi.trace\n");
}