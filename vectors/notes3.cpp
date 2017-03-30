// Passing Vectors
void modify(vector<int> & v) {
    int size=v.size();
    
    for(int i=0; i<size; i++) {
        v[i]++;
    }
}

void print(const vector<int> & v) {
    int size=v.size();
    for(int i=0; i<size; i++) {
        cout << v[i] << '';
    }
    cout << endl;
}
