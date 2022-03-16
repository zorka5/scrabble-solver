#pragma once
#include <iostream>


template <typename T>
/**
 * @brief The ListNode class
 * Klasa reprezentująca element listy
 */
class ListNode{
public:
    T data;
    ListNode<T> *next;

    ListNode(): next(nullptr){}
    //ListNode(const T& new_data): data(new_data), next(nullptr){}
};


template <typename T>
/**
 * @brief The List class
 * Klasa reprezentująca listę dynamiczną
 */
class List{
public:
    List(): head(nullptr), tail(nullptr){} ///Konstruktor klasy List
    List(const List &other); ///Konstruktor kopiujacy klasy List
    ~List(); ///Destruktor

private:
    ListNode<T> *head; ///wskaźnik na pierwszy element listy
    ListNode<T> *tail; ///wskaźnik na ostatni element listy

public:
    /**
     * @brief add_last
     * Funckja dodająca wartość na koneic listy
     * @param value element, który ma zostać dodany
     */
    void add_last(T value);

    /**
     * @brief print_all
     * Funkcja wypisująca listę
     */
    void print_all();

    /**
     * @brief get_size
     * Funkcja zwracająca aktualny rozmiar listy
     * @return rozmiar listy
     */
    size_t get_size();

    /**
     * @brief get_head
     * Funkcja zwracająca wskaźnik na pierwszy element listy
     * @return głowa
     */
    ListNode<T> *get_head() {return head;}


    template<typename N>
    /**
     * @brief The IteratorBase class
     * Klasa reprezentująca iterator po klasie List
     */
    class IteratorBase
    {
        friend class List; /// Zaprzyjaźnienie klasy List pozwala na dostęp do pół prywatnych i chronionych
    private:
        ListNode<T>* current; /// Wskaźnik na aktualny element listy
    public:
        IteratorBase(ListNode<T>* node): current(node){}
        bool operator==(IteratorBase const& itbase) const {return current == itbase.current;}
        bool operator!=(IteratorBase const& itbase) const {return !(*this == itbase);}

        IteratorBase& operator++() {current = current->next;return *this;}
        IteratorBase& operator--() {current = current->prev;return *this;}
        IteratorBase  operator++(int) {IteratorBase result(*this); ++(*this);return result;}
        IteratorBase  operator--(int) {IteratorBase result(*this); --(*this);return result;}

        T& operator*() const {return static_cast<ListNode<T>*>(current)->data;}
        T* operator->() const {return &static_cast<ListNode<T>*>(current)->data;}
    };

public:
    using iterator = IteratorBase<T>;
    using const_iterator = IteratorBase<T const>;

    /**
     * @brief begin
     * Funkcja zwracająca iterator na pierwszy element listy
     * @return iterator begin
     */
    iterator begin() const {return iterator(head);}

    /**
     * @brief end
     * Funckja zwracająca iterator na ostatni element listy
     * @return iterator end
     */
    iterator end() const {return iterator(tail);}

};


template <typename T>
List<T>::List(const List & obj): head(nullptr)
{
    if(obj.head == nullptr)
    {
        head = nullptr;
    }
    else
    {
        ListNode<T> *node = obj.head;
        while(node != nullptr)
        {
            add_last(node->data);
            node = node->next;
        }
    }
}

template <typename T>
List<T>::~List()
{
    ListNode<T> *temp = this->head;
    while(temp)
    {
        ListNode<T> *next = temp->next;
        delete temp;
        temp = next;
    }

}

template <typename T>
void List<T>::add_last(T data)
{
    ListNode<T> *newNode = new ListNode<T>;
    newNode->data = data;
    newNode->next = nullptr;

    if(head==nullptr)
    {
        head = newNode;
    }
    else
    {
        ListNode<T> *temp = head;
        while(temp->next !=nullptr)
            temp = temp->next;
        temp->next = newNode;
    }
}


template <typename T>
void List<T>::print_all()
{
    ListNode<T> *temp = head;
    while(temp !=nullptr)
    {
        std::wcout << temp->data <<  std::endl;
        temp=temp->next;
    }
    std::wcout << std::endl;
}



template <typename T>
size_t List<T>::get_size()
{
    size_t count = 0;
    ListNode<T> *temp = head;
    while(temp!=nullptr)
    {
        count++;
        temp= temp->next;
    }

    return count;
}




