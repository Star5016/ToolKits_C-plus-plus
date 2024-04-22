#include <iostream>
using namespace std;
#define MAXSIZE 100
typedef int ElemType;
class SqList{
public:
    ElemType *data;
    int length;
    //Constructor of SqList
    SqList(){
        this->data = new ElemType [MAXSIZE];
        length = 0;
    }
    //Copy from Array
    bool CopyArray(ElemType a[], int n){
        if (this->length + n > MAXSIZE){cout<<"Out Of Range"<<endl;return false;}
        for(int i = 0; i < n; i++){
            this->data[i] = a[i];
        }
        length += n;
        return true;
    }


    //Destructor of SqList
    ~SqList(){
        delete this->data;
    }

    // print the list
    void print(){
        if(this->length==0){
            cout << "Empty List" << endl;
            return;
        }
        else{
            for(int i = 0; i < length; i++){
                cout << this->data[i] << " ";
            }
            cout << endl;
        }

    }

    // Get the length of the list
    int getLength(){
        return length;
    }

    /*
     *Get the element at the i-1th position
     *Return -1 if the index is out of range
     *Else return i-1th element
    */
    ElemType getElem(int i){
        if(i < 1 || i > length){
            cout << "Index out of range" << endl;
            return -1;
        }
        return this->data[i-1];
    }

    /*
     * Get the index of the first element that equals to e
     * Return -1 if there is no such element
     */
    int locateElem(ElemType e){
        for(int i = 0; i < length; i++){
            if(this->data[i] == e){
                return i;
            }
        }
        return -1;
    }

    /*
     * Insert e at the i-1th position
     * Return false if the index is out of range
     * Else return true*/
    bool insertElem(int i, ElemType e){
        if (i<1||i>length+1){
            cout<<"Index out of range"<<endl;
            return false;
        }
        for(int j=this->length;j>=i;j--) {
            this->data[j] = this->data[j - 1];
        }
        this->data[i-1]=e;
        this->length++;
        return true;
    }

    bool deleteElem(int i,ElemType &e){
        if(i<1||i>length){
            cout<<"Index out of range"<<endl;
            return false;
        }
        e=this->data[i-1];
        for(int j=i;j<length;j++){
            this->data[j-1]=this->data[j];
        }
        this->length--;
        return true;
    }
};

void test(){
    int a[5] = {1,2,3,4,5};
    SqList list;
    list.CopyArray(a,5);
    list.print();
    list.insertElem(1,6);
    list.print();
    ElemType e;
    cout<<"The index of elem 3 is "<<list.locateElem(3)<<endl;
    list.deleteElem(1,e);
    cout<<"e = "<<e<<endl;
    list.print();
}

int main(){
    test();
    return 0;
}
