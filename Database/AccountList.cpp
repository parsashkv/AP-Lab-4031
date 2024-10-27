#include "AccountList.h"


AccountList::AccountList(){}

AccountList::AccountList(Account* _head)
	: head(_head),size(1){}

void AccountList::addAccount(Account* _accountToAdd)
{
   Account *account = new Account(*_accountToAdd);
    this->at(size-1).next= new Account(*account);   
    size++;
}

Account* AccountList:: getHead()const { return head; }

void AccountList::swap(Account& acc1, Account& acc2)
{

    Account* prevX = nullptr, * currX = nullptr;
    Account* prevY = nullptr, * currY = nullptr;
    Account* curr = head;

    // First loop to find x
    while (curr != nullptr) {
        if (curr->getUniqeId() == acc1.getUniqeId()) {
            currX = curr;
            break;
        }
        prevX = curr;
        curr = curr->next;
    }

    curr = head;

    // Second loop to find y
    while (curr != nullptr) {
        if (curr->getUniqeId() == acc2.getUniqeId()) {
            currY = curr;
            break;
        }
        prevY = curr;
        curr = curr->next;
    }

    // If either x or y is not present, nothing to do
    if (currX == nullptr || currY == nullptr) return;

    // If x is not head of the linked list
    if (prevX != nullptr) {
        prevX->next = currY;
    }
    else {
        head = currY;
    }

    // If y is not head of the linked list
    if (prevY != nullptr) {
        prevY->next = currX;
    }
    else {
        head = currX;
    }

    // Swap next pointers
    Account* temp = currY->next;
    currY->next = currX->next;
    currX->next = temp;

    return ;
}
  

Account& AccountList::at(int index)
{
    Account* current = head;
    for (size_t i = 0; i < index; i++)
    {
        current = current->next;
    }
    return *current;
}


Account *merge(Account *first, Account *second)
{

    if (first == nullptr) return second;
    if (second == nullptr) return first;
    {
        first->next = merge(first->next, second);
        return first;
    }
    else {
        second->next = merge(first, second->next);
        return second;
    }
}

Account *MergeSort(Account *head)
{
    if (head == nullptr || head->next == nullptr)
        return head;

// Split the list into two halves
    Node *second = split(head);

// Recursively sort each half
    head = MergeSort(head);
    second = MergeSort(second);

// Merge the two sorted halves
    return merge(head, second);
}


void AccountList::print()
{
    Account* current = head;
    for (size_t i = 0; i < size; i++)
    {
        current->print();
        current = current->next;
    }
}