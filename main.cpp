#include <iostream>
using namespace std;

struct lista_element
{
    int nr;
    lista_element* next;
};
class lista
{
    lista_element* l;

public:
    // Pusta lista
    lista()
    {
        l = NULL;
    }
    // Dodawanie
    void dodaj(int numer)
    {
        lista_element* p = new lista_element;
        p->nr = numer;
        p->next = NULL;
        if (l == NULL)
        {
            l = p;
        }
        else
        {
            lista_element* q = l;
            while (q->next != NULL)
                q = q->next;
            q->next = p;
        }
    }
    // Usuwanie ostatniego
    int usun_ostatniego()
    {
        if (l == NULL)
            return -1;
        if (l->next == NULL)
        {
            int numer = l->nr;
            delete l;
            l = NULL;
            return numer;
        }
        lista_element* q = l;
        while (q->next->next != NULL)
        {
            q = q->next;
        }
        int numer = q->next->nr;
        delete q->next;
        q->next = NULL;
        return numer;
    }
    // Wypisywanie
    void wypisz()
    {
        lista_element* q = l;
        while (q != NULL)
        {
            cout << q->nr << " ";
            q = q->next;
        }
        cout << endl;
    }
};

int main()
{
    lista l;
    l.dodaj(7);
    l.dodaj(10);
    l.dodaj(15);
    l.wypisz();
    cout << "Usunieto: " << l.usun_ostatniego() << endl;
    l.wypisz();
    return 0;
}
