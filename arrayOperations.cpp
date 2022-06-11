/*
Basic Array Operations (03/06/22, Sadman Mehrab)
  -> create array objects with specified size
  -> insert operations for all positional cases
  -> delete operations for all positional cases
  -> utility operations: print, count, search etc.
*/

#include<iostream>
#define BOOST ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
using namespace std;

  class ArrayOperations{
  private:
    int lastIndex = -1;
    int size = 0;
    int *arr = new int[size];

  public:

    //constructors
    ArrayOperations(int s){
      size = s;
    }

    ArrayOperations(int s, int f){
      size = s;
      for(int i=0;i<size;i++){
        arr[++lastIndex] = f;
      }
    }

    //insert operations
    void insertLast(int v){
      if(full()) cout<<"Cannot Insert, Array is Full.\n";
      else{
        arr[++lastIndex] = v;
      }
    }

    void insertFirst(int v){
      if(full()) cout<<"Cannot Insert, Array is Full.\n";
      else{
        lastIndex++;
        for(int i=lastIndex;i>0;i--){
          arr[i] = arr[i-1];
        }
        arr[0] = v;
      }
    }

    void insertAt(int p, int v){
      if(full()) cout<<"Cannot Insert, Array is Full.\n";
      else if(p<0 || p>lastIndex) cout<<"Cannot Insert, Invalid Position.\n";
      else{
        lastIndex++;
        for(int i=lastIndex;i>p;i--){
          arr[i] = arr[i-1];
        }
        arr[p] = v;
      }
    }

    void insertAfter(int t, int v){
      if(getPosition(t) == -1) cout<<"Cannot Insert, Element Not Found.\n";
      else insertAt(getPosition(t)+1, v);
    }

    void insertBefore(int t, int v){
      if(getPosition(t) == -1) cout<<"Cannot Insert, Element Not Found.\n";
      else insertAt(getPosition(t)-1, v);
    }

    //delete operations
    void deleteLast(){
      if(empty()) cout<<"Cannot Delete, Array Is Empty.\n";
      else lastIndex--;
    }

    void deleteFirst(){
      if(empty()) cout<<"Cannot Delete, Array Is Empty.\n";
      else{
        lastIndex--;
        for(int i=0;i<=lastIndex;i++){
          arr[i] = arr[i+1];
        }
      }
    }

    void deleteAt(int p){
      if(p<0 || p>lastIndex) cout<<"Cannot Delete, Invalid Position.\n";
      lastIndex--;
      for(int i=p;i<=lastIndex;i++){
        arr[i] = arr[i+1];
      }
    }

    void deleteElement(int t){
      if(getPosition(t) == -1) cout<<"Cannot Delete, Element Not Found.\n";
      else deleteAt(getPosition(t));
    }


    //utility operations
    int getCount(){ return lastIndex + 1;}
    bool full(){ return lastIndex == size-1;}
    bool empty(){ return lastIndex == -1;}

    int getPosition(int f){
      for(int i=0;i<=lastIndex;i++) if (arr[i] == f) return i;
      return -1;
    }

    void printArray(){
      if(empty()) cout<<"Cannot Print, Array Is Empty.\n";
      else{
        cout<<"Printing Array: \n";
        for(int i=0;i<=lastIndex;i++){
          cout<<arr[i]<<" ";
        }
        cout<<"\n";
      }
    }

  };

int main(){
  BOOST
  //play around as you wish :)
  ArrayOperations arr(15);


return 0;}
