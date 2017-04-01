// Bubble Sort
// repeatedly steps through the list to be sorted
// compares each pair of adjacent items and swaps them if they are in the wrong order.
// must make multiple passes to completly sort list

void SortA(string myA[], size) {
    bool sorted=false;
    string temp;
    int i;

    while(!sorted) {
        sorted = true;
        for(i=1; i<size; i++) {
            if(myA[i-1] < myA[i]) {
                temp = myA[i-1];
                myA[i-1] = myA[i];
                myA[i] = temp;
                sorted = false;
            }
        }
    }

}

// Selection Sort
// find the smalest element and swap it into the first position

void selectionSort(int a[], int size) {
    int step, i, saveElement, smallest;
    for(step=0; step<size; step++) {
        smallest = step;

        for(i=step+1; s<size; i++) {
            if(a[i] < a[smallest]) {
                smallest = i;
            }
        }

        if(smallest != step) {
            saveElement = a[step];
            a[step] = a[smallest];
            a[smallest] = saveElement;
        }
    }
}
