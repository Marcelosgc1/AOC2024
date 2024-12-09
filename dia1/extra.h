



void swap(int** array, int i, int j){
    int aux = (*array)[j];
    (*array)[j] = (*array)[i];
    (*array)[i] = aux;
}

int mySort(int** array, int left, int right){
    int len = right - left;
    int pivot = left + (len / 2);

    int aux = (*array)[pivot];
    (*array)[pivot] = (*array)[left];
    (*array)[left] = aux;

    int j = left;

    for (int i = left + 1; i <= right; i++){
        if ((*array)[i] < (*array)[left]){
            j++;
            swap(array, i, j);
        }
    }
    
    swap(array, j, left);
    
    return j;
}

void quickSort(int** array, int left, int right){
    if (left < right){
        int pivot = mySort(array, left, right);
		quickSort(array, left, pivot - 1);
		quickSort(array, pivot + 1, right);	
    }
}