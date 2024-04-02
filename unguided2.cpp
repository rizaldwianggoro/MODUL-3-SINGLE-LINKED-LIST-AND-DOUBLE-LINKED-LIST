#include <iostream>
#include <iomanip>
#include <string>
using namespace std;

struct Node
{
    string nama;
    int harga;
    Node *prev;
    Node *next;
};

class DoubleLinkedList
{
private:
    Node *head;
    Node *tail;
    int size;

public:
    DoubleLinkedList()
    {
        head = NULL;
        tail = NULL;
        size = 0;
    }

    void addData(string nama, int harga)
    {
        Node *node = new Node;
        node->nama = nama;
        node->harga = harga;
        node->prev = tail;
        node->next = NULL;
        if (head == NULL)
        {
            head = node;
            tail = node;
        }
        else
        {
            tail->next = node;
            tail = node;
        }
        size++;
    }

    void addDataAt(int index, string nama, int harga)
    {
        if (index < 0 || index > size)
        {
            cout << "Index out of bounds" << endl;
            return;
        }
        Node *node = new Node;
        node->nama = nama;
        node->harga = harga;
        if (index == 0)
        {
            node->prev = NULL;
            node->next = head;
            head->prev = node;
            head = node;
        }
        else if (index == size)
        {
            node->prev = tail;
            node->next = NULL;
            tail->next = node;
            tail = node;
        }
        else
        {
            Node *current = head;
            for (int i = 0; i < index - 1; i++)
            {
                current = current->next;
            }
            node->prev = current;
            node->next = current->next;
            current->next->prev = node;
            current->next = node;
        }
        size++;
    }

    void deleteDataAt(int index)
    {
        if (index < 0 || index >= size)
        {
            cout << "Index out of bounds" << endl;
            return;
        }
        if (index == 0)
        {
            Node *temp = head;
            head = head->next;
            head->prev = NULL;
            delete temp;
        }
        else if (index == size - 1)
        {
            Node *temp = tail;
            tail = tail->prev;
            tail->next = NULL;
            delete temp;
        }
        else
        {
            Node *current = head;
            for (int i = 0; i < index; i++)
            {
                current = current->next;
            }
            current->prev->next = current->next;
            current->next->prev = current->prev;
            delete current;
        }
        size--;
    }

    void clearData()
    {
        while (head != NULL)
        {
            Node *temp = head;
            head = head->next;
            delete temp;
        }
        tail = NULL;
        size = 0;
    }

    void displayData()
    {
        cout << setw(15) << left << "Nama Produk" << setw(10) << left << "Harga" << endl;
        Node *current = head;
        while (current != NULL)
        {
            cout << setw(15) << left << current->nama << setw(10) << left << current->harga << endl;
            current = current->next;
        }
    }

    void updateDataAt(int index, string nama, int harga)
    {
        if (index < 0 || index >= size)
        {
            cout << "Index out of bounds" << endl;
            return;
        }
        Node *current = head;
        for (int i = 0; i < index; i++)
        {
            current = current->next;
        }
        current->nama = nama;
        current->harga = harga;
    }
};

int main()
{
    DoubleLinkedList dll;
    int pilihan;
    string nama;
    int harga;
    int index;
    do
    {
        cout << "MENU" << endl;
        cout << "1. Tambah data diawal" << endl;
        cout << "2. Tambah data setelah data tertentu" << endl;
        cout << "3. Update data" << endl;
        cout << "4. Hapus data" << endl;
        cout << "5. Bersihkan semua data" << endl;
        cout << "6. Tampilkan data" << endl;
        cout << "7. Exit" << endl;
        cout << "Pilih: ";
        cin >> pilihan;
        switch (pilihan)
        {
        case 1:
            cout << "Nama Produk: ";
            cin >> nama;
            cout << "Harga: ";
            cin >> harga;
            dll.addData(nama, harga);
            break;
        case 2:
            cout << "Index: ";
            cin >> index;
            cout << "Nama Produk: ";
            cin >> nama;
            cout << "Harga: ";
            cin >> harga;
            dll.addDataAt(index, nama, harga);
            break;
        case 3:
            cout << "Index: ";
            cin >> index;
            cout << "Nama Produk: ";
            cin >> nama;
            cout << "Harga: ";
            cin >> harga;
            dll.updateDataAt(index, nama, harga);
            break;
        case 4:
            cout << "Index: ";
            cin >> index;
            dll.deleteDataAt(index);
            break;
        case 5:
            dll.clearData();
            break;
        case 6:
            dll.displayData();
            break;
        case 7:
            break;
        default:
            cout << "Pilihan tidak valid" << endl;
            break;
        }
        cout << endl;
    } while (pilihan != 7);
    return 0;
}
