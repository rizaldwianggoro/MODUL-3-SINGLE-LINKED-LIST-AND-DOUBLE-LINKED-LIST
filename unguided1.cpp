#include <iostream>

// 2311102034_Rizal Dwi Anggoro
using namespace std;

class Node
{
public:
    string nama;
    int usia;
    Node *next;
};

class LinkedList
{

public:
    Node *head;
    LinkedList()
    {
        head = NULL;
    }

    void AddData(string nama, int usia)
    {
        Node *newNode = new Node();
        newNode->nama = nama;
        newNode->usia = usia;
        newNode->next = head;
        head = newNode;
    }

    void insertAtEnd(string nama, int usia)
    {
        Node *newNode = new Node();
        newNode->nama = nama;
        newNode->usia = usia;
        newNode->next = NULL;
        if (head == NULL)
        {
            head = newNode;
            return;
        }
        Node *temp = head;
        while (temp->next != NULL)
        {
            temp = temp->next;
        }
        temp->next = newNode;
    }

    void insertAfter(string nama, int usia, string keynama)
    {
        Node *temp = head;
        while (temp != NULL)
        {
            if (temp->nama == keynama)
            {
                Node *newNode = new Node();
                newNode->nama = nama;
                newNode->usia = usia;
                newNode->next = temp->next;
                temp->next = newNode;
                return;
            }
            temp = temp->next;
        }
        cout << keynama << " Tidak Ada" << endl;
    }
    
    void updateNode(string nama, int usia)
    {
        Node *temp = head;
        while (temp != NULL)
        {
            if (temp->nama == nama)
            {
                temp->usia = usia;
                return;
            }
            temp = temp->next;
        }
        cout << nama << " Tidak Ada" << endl;
    }

    void deleteNode(string nama)
    {
        Node *temp = head;
        Node *prev = NULL;
        while (temp != NULL)
        {
            if (temp->nama == nama)
            {
                if (prev == NULL)
                {
                    head = temp->next;
                }
                else
                {
                    prev->next = temp->next;
                }
                delete temp;
                return;
            }
            prev = temp;
            temp = temp->next;
        }
        cout << nama << " Tidak Ada" << endl;
    }

    void clearAll()
    {
        Node *temp = head;
        while (temp != NULL)
        {
            Node *next = temp->next;
            delete temp;
            temp = next;
        }
        head = NULL;
    }

    // Display all nodes
    void display()
    {
        Node *temp = head;
        while (temp != NULL)
        {
            cout << "Nama Anda : " << temp->  nama << ", usia: " << temp->  usia << endl;
            temp = temp->next;
        }
    }
};
// Main function
int main()
{
    LinkedList list;
    int pilihan, position, usia;
    string nama, keynama;

    do
    {
        cout << endl;
        cout << "MENU" << endl;
        cout << "1. Tambah data diawal" << endl;
        cout << "2. Tambah data diakhir" << endl;
        cout << "3. Tambah data setelah data tertentu" << endl;
        cout << "4. Update data" << endl;
        cout << "5. Hapus data" << endl;
        cout << "6. Bersihkan data" << endl;
        cout << "7. Tampilkan data" << endl;
        cout << "8. Exit" << endl;
        cout << "Enter your choice: ";
        cin >> pilihan;
        switch (pilihan){
        case 1:
            cout << "Masukan Nama: ";
            cin >> nama;
            cout << "Masukan Usia: ";
            cin >> usia;
            list.AddData(nama, usia);
            break;
        case 2:
            cout << "Masukan Nama: ";
            cin >> nama;
            cout << "Masukan Usia: ";
            cin >> usia;
            list.AddData(nama, usia);
            break;
        case 3:
            cout << "Masukan Nama: ";
            cin >> nama;
            cout << "Masukan Usia: ";
            cin >> usia;
            cout << "Masukan Nama Setelah: ";
            cin >> keynama;
            list.insertAfter(nama, usia, keynama);
            break;
        case 4:
            cout << "Masukan Update Nama: ";
            cin >> nama;
            cout << "Masukan Update Usia: ";
            cin >> usia;
            list.updateNode(nama, usia);
            break;
        case 5:
            cout << "Masukan Nama yang Dihapus: ";
            cin >> nama;
            list.deleteNode(nama);
            break;
        case 6:
            list.clearAll();
            break;
        case 7:
            list.display();
            break;
        case 8:
            cout << "Keluar program" << endl;
            break;
        default:
            cout << "Salah Pilihan" << endl;
        }
    } while (pilihan != 8);
    return 0;
}
