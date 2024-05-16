#include <forward_list>
#include <iostream>
using namespace std;

void show_fl(forward_list<int> k) {
  for (int i : k) {
    cout << i << " ";
  }
  cout << "\n";
}
int main() {
  // Initializing forward list
  forward_list<int> flist = {10, 20, 30, 40, 50};
  cout << "The forward list : ";
  show_fl(flist);

  /*Iterators are used to point to the containers in STL,
  because of iterators it is possible for an algorithm to manipulate
  different types of data structures/Containers. We will learn more about
  iterators shortly*/
  forward_list<int>::iterator ptr;

  flist.push_front(60);
  cout << "The forward list after push_front operation : ";
  show_fl(flist);

  flist.emplace_front(70);
  cout << "The forward list after emplace_front operation : ";
  show_fl(flist);

  flist.pop_front();
  cout << "The forward list after pop_front operation : ";
  show_fl(flist);

  ptr = flist.insert_after(flist.begin(), {1, 2, 3});
  cout << "The forward list after insert_after operation : ";
  show_fl(flist);

  ptr = flist.emplace_after(ptr, 2);
  cout << "The forward list after emplace_after operation : ";
  show_fl(flist);

  ptr = flist.erase_after(ptr);
  cout << "The forward list after erase_after operation : ";
  show_fl(flist);

  flist.remove(40);
  cout << "The forward list after remove operation : ";
  show_fl(flist);

  flist.remove_if([](int x) { return x > 20; });
  cout << "The forward list after remove_if operation : ";
  show_fl(flist);

  return 0;
}

/*
Important functions supported by a forward list:

assign() - Used to assign elements in the forward list.

push_front() - Inserts the element at the first position of a forward list. The
value from this function is copied to the space before the first element in the
container. The size of the forward list increases by 1.

emplace_front() - similar to the previous function but in this no copying
operation occurs, the element is created directly at the memory before the first
element of the forward list.

pop_front() - This function is used to delete the first element of list.

insert_after()- This function gives us a choice to insert elements at any
position in the forward list. The arguments in this function are copied at the
desired position.

emplace_after() -This function also does the same operation as above function
but the elements are directly made without any copy operation.

erase_after() - This function is used to erase elements from a particular
position in the forward list.

remove() - This function removes the particular element from the forward list
mentioned in its argument.

remove_if() - This function removes according to the condition in its argument.

splice_after() - This function transfers elements from one forward list to
other.
*/