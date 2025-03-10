#ifndef HEAP_H
#define HEAP_H
#include <functional>
#include <stdexcept>
#include <vector>
#include <algorithm>

template <typename T, typename PComparator = std::less<T> >
class Heap
{
public:
  /**
   * @brief Construct a new Heap object
   * 
   * @param m ary-ness of heap tree (default to 2)
   * @param c binary predicate function/functor that takes two items
   *          as an argument and returns a bool if the first argument has
   *          priority over the second.
   */
  Heap(int m=2, PComparator c = PComparator());

  /**
  * @brief Destroy the Heap object
  * 
  */
  ~Heap();

  /**
   * @brief Push an item to the heap
   * 
   * @param item item to heap
   */
  void push(const T& item);

  /**
   * @brief Returns the top (priority) item
   * 
   * @return T const& top priority item
   * @throw std::underflow_error if the heap is empty
   */
  T const & top() const;

  /**
   * @brief Remove the top priority item
   * 
   * @throw std::underflow_error if the heap is empty
   */
  void pop();

  /// returns true if the heap is empty

  /**
   * @brief Returns true if the heap is empty
   * 
   */
  bool empty() const;

    /**
   * @brief Returns size of the heap
   * 
   */
  size_t size() const;

private:
  /// Add whatever helper functions and data members you need below

  std::vector<T> vec_;
  int m_;
  PComparator c_;

};

// Add implementation of member functions here


// We will start top() for you to handle the case of 
// calling top on an empty heap
template <typename T, typename PComparator>
T const & Heap<T,PComparator>::top() const
{
  // Here we use exceptions to handle the case of trying
  // to access the top element of an empty heap
  if(empty()){
    // ================================
    // throw the appropriate exception
    // ================================
    throw std::underflow_error("No items in heap!");

  }
  // If we get here we know the heap has at least 1 item
  // Add code to return the top element
  return vec_[0];


}

template <typename T, typename PComparator>
bool Heap<T,PComparator>::empty() const{
  return vec_.empty();
}

template <typename T, typename PComparator>
Heap<T,PComparator>::Heap(int m, PComparator c): m_(m), c_(c){

}


template <typename T, typename PComparator>
Heap<T,PComparator>::~Heap(){

}

template <typename T, typename PComparator>

void Heap<T,PComparator>::push(const T& item){
  vec_.push_back(item);
  std::size_t index = vec_.size() - 1;
  while (index != 0) {
      std::size_t parent_index = (index - 1) / m_;
      if (!c_(vec_[index], vec_[parent_index])) {
          break;
      }
      std::swap(vec_[index], vec_[parent_index]);
      index = parent_index;
  }
}

template <typename T, typename PComparator>
size_t Heap<T,PComparator>::size() const{
  return vec_.size();
}

// We will start pop() for you to handle the case of 
// calling top on an empty heap
template <typename T, typename PComparator>
void Heap<T,PComparator>::pop()
{
  if(empty()){
    // ================================
    // throw the appropriate exception
    // ================================
    throw std::underflow_error("No items in heap!");

  }
  vec_[0] = vec_.back();
  vec_.pop_back();

  if(!empty()){
    int index=0;
    int size_ = vec_.size();
    while(true){
      int largest = index;
      for(int i=0; i<m_; i++){
        int child = m_*index + i+1;
        if(child<size_ && c_(vec_[child], vec_[largest])){
          largest=child;
        }
      }
      if(largest!=index){
        std::swap(vec_[index], vec_[largest]);
        index=largest;
      }else{
        break;
      }
    }
  }

}



#endif

