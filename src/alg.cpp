// Copyright 2021 NNTU-CS
int countPairs1(int *arr, int len, int value) {
  int count = 0;
  for (int i = 0; i < len ; i++) {
    for (int j = i + 1; j < len; j++) {
      if (arr[i] + arr[j] == value)
        count++;
    }
  }

  return count;
}
int countPairs2(int *arr, int len, int value) {
  int count = 0;
  for (int i = 0; i < len; i++) {
    if (arr[i] >= value)
      continue;
    for (int j = len - 1; j > i; j--) {
      if (arr[i] + arr[j] > value)
        continue;
      else if (arr[i] + arr[j] < value)
        break;
      count++;
      int k = j - 1;
      while (k > i && arr[k] == arr[j]) {
        count++;
        k--;
      }
      break;
    }
  }
  return count;
}
int countPairs3(int *arr, int len, int value) {
  int count = 0;
  for (int i = 0; i < len; i++) {
    if (arr[i] >= value)
      continue;
    int target = value - arr[i];
    int left = i + 1;
    int right = len - 1;
    if (arr[right] < target || arr[left] > target)
      continue;
    while (left <= right) {
      int mid = left + (right - left) / 2;
      if (arr[mid] == target) {
        int j = mid;
        while (j < len && arr[j] == target) {
          count++;
          j++;
        }
        j = mid - 1;
        while (j > i && arr[j] == target) {
          count++;
          j--;
        }
        break;
      } else if (arr[mid] < target) {
        left = mid + 1;
      } else {
        right = mid - 1;
      }
    }
  }

  return count;
}
