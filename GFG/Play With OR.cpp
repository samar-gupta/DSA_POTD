int* game_with_number(int arr[], int n) {
    
    for(int i=0;i<=n-2;i++){
        arr[i] = arr[i] | arr[i+1];
    }
    
    return arr;
}
