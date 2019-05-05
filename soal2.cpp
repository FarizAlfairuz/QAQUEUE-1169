#include<iostream>
using namespace std;

const int maxElemen = 4;

struct Queue
{
    char isi[maxElemen];
    int head;
    int tail;
};

typedef Queue qu[20];

void createQueue (qu& Q, int& num)
{
    Q[num].head = 0;
    Q[num].tail = -1;
}

void insertQueue(qu& Q, char elemen, int& num, int& loop)
{
    loop = 0;
    // cout << "Insert Queue (Antrian) : " << num+1 << endl;
    if (Q[num].tail == maxElemen-1)
    {
        cout << "Antrian sudah penuh" << endl;
        loop = 1;
        // ++num;
        // createQueue(Q, num);
        // insertQueue(Q, elemen, num);
    }
    else
    {

        Q[num].tail = Q[num].tail + 1;
        Q[num].isi[Q[num].tail] = elemen;
    }
}

// void deleteQueue(qu& Q, char& elemenHapus, int num)
// {
//     cout << "Delete Queue (Antrian) " << endl;
//     if (Q[num].head > Q[num].tail)
//     {
//         cout << "Antrian kosong" << endl;
//     }
//     else
//     {
//         elemenHapus = Q[num].isi[Q[num].head]; //Q.head=0
//         for (int i=0; i<Q[num].tail; i++)
//         { // Geser ke depan
//             Q[num].isi[i] = Q[num].isi[i+1];
//         }
//         Q[num].tail = Q[num].tail-1;
//     }
// }

main()
{
    qu q;
    int n, num = 0, loop;
    char c;

    createQueue(q,num);
    cout << "Banyak data : "; cin >> n;
    for(int i = 0; i < n; i++)
    {
        if (loop == 1)
        {
            num++;
            createQueue(q,num);
            for(int j = 0; i < n; i++)
            {
                insertQueue(q,c,num, loop);
                cout << "Antrian ke-" << i+1 << " : "; cin >> q[num].isi[q[num].tail];
            }
        }
        else
        {
            
            cout << "bAntrian ke-" << i+1 << " : "; cin >> q[num].isi[q[num].tail];
            insertQueue(q,c,num, loop);
        }
    }
    
    for(int  i = 0; i < n; i++)
    {
        cout << "kAntrian ke-" << i+1 << " : "<< q[i].isi[q[i].tail] << endl;
    }
    
}