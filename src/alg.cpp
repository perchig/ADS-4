int countPairs1(int *arr, int len, int value) {
  int count = 0;
  for (int i = 0; i < len ; i++){
    for (int j = 0; j < len; j++){
      if (arr[i] + arr[j] == value)
        count++;
    }
  }

  return count;
}

int countPairs2(int *arr, int len, int value) {
  int count = 0;
  for (int i = 0; i < len ; i++){
    if (arr[i] >= value)
      continue;
    for (int j = len - 1; j >= i; j--){
      if (arr[i] + arr[j] > value)
        continue;
      else if (arr[i] + arr[j] < value)
        break;
      else {
        count++;
        break;
      }
    }
  }

  return count;
}

int countPairs3(int *arr, int len, int value) {
  int count = 0;
  for (int i = 0; i < len; i++){
    int target = value - arr[i];
    if (arr[i] > value && value > 0)
      continue;
    int left = i + 1;
    int right = len - 1;
    while (left <= right){
      int mid = (left + right) / 2;
      if (arr[mid] == target){
        count++;
        break;
      }
      else if (arr[mid] < target)
        left = mid + 1;
      else
        right = mid - 1;
    }
  }
  
  return count;
}
