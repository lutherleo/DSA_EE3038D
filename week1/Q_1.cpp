/*The Sorting Problem can be formally stated in terms of the input/output relationship as follows:
Input: A sequence of n numbers a1, a2, ..., an
Output: A permutation a1, a2, ..., an of the input sequence such that a1 ≤ a2 ≤ ... ≤ an
Let A[1 .. n] be an array of n distinct numbers.
If i < j and A[i] > A[j], then the pair (i, j) is called an inversion of A.
Write a program that uses the Merge-Sort algorithm for sorting a given input sequence of integers present in an
array A.Your program must print the number of inversions in the input array.
*/

#include <iostream>

using namespace std;
 
int getcount(int A[], int m)
{
    int count = 0;
    for (int i = 0; i < m - 1; i++){
        for (int j = i + 1; j < m; j++){
            if (A[i] > A[j]){
                count++;
            }
        }
    }
 
    return count;
}



void merge(int A[], int p, int q, int r)
{
    int i, j, n1=q-p+1, n2=r-q;
    int Left[n1], Right[n2];

    for(i=0;i<n1;i++)
        Left[i]=A[p+i];
    for(i=0;i<n2;i++)
        Right[i]=A[q+1+i];

    i = j = 0;
    int k = p;
    while(i<n1 && j<n2)
    {
        if(Left[i] <= Right[j])
        {
            A[k] = Left[i++];
            k++;
        }
        else
        {
            A[k] = Right[j++];
            k++;
        }
    }

    while(i<n1)
    {
        A[k] = Left[i++];
        k++;
    }

    while(j<n2)
    {
        A[k] = Right[j++];
        k++;
    }
}

void merge_sort(int a[], int p, int r)
{
    if(p<r)
    {
        int q = p+(r-p)/2;

        merge_sort(a, p, q);
        merge_sort(a, q+1, r);
        merge(a, p, q, r);
    }
}

void print(int A[], int n)
{
    for(int i=0;i<n;i++)
        cout << A[i]<< " " ;
}

int main()
{
    int n;
    cin>>n;
    int A[n];
    for (int i = 0; i < n; i++)
        cin >> A[i];
    int count = getcount(A, n);
    merge_sort(A,0, n-1);
    
    print(A, n);
    cout << endl;
    cout << count <<endl;
    return 0;
}
