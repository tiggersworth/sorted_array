/***
*  File: a2.hpp
*  Author: Tammy Chang 
*/

#ifndef A2_HPP
#define A2_HPP


#include <algorithm>
using namespace std;


class sorted_sc_array {
public:
	explicit sorted_sc_array() : size_(0), ptr_(nullptr) {
		if (size_ == 0) ptr_ = nullptr;

        buckets = new int[numbuckets];
       for (int i = 0; i < numbuckets; ++i) { // loops from -128 to 127
            buckets[i] = 0;
        }
	}
	sorted_sc_array(const sorted_sc_array& A) {
        size_ = A.size_;
		if (size_ == 0) ptr_ = nullptr;
		else {

			ptr_ = new signed char[size_];
			std::copy(A.ptr_, A.ptr_ + size_, A.ptr_);

            //std::copy(A.buckets, A.buckets + actualnumbuckets, buckets);
		}
        buckets = new int[numbuckets];
        std::copy(A.buckets, A.buckets+ numbuckets, buckets);
           //for (int i = 0; i < numbuckets; ++i) { buckets[i] = A.buckets[i]; }

	}

	
	sorted_sc_array& operator=(const sorted_sc_array& A) {
		if (this == &A) return *this; // self assignment
        delete[] ptr_;
		size_ = A.size();
		if (size_ == 0) ptr_ = nullptr;
		else {

		//	ptr_ = new signed char[size_];
		//	std::copy(A.ptr_, A.ptr_ + size_, ptr_);
        //for (int i = 0; i < numbuckets; ++i) { buckets[i] = A.buckets[i]; }

        std::copy(A.buckets, A.buckets+numbuckets, buckets);
        //    buckets = new int[numbuckets];

		}
		return *this;
		// operator
	}

	// RETURNS SIZE OF THE ARRAY (i.e. HOW MANY ELEMENTS IT STORES)
	int size() const {
			return size_;
	}

    // AFTER INSERT COMPLETES THE ARRAY MUST BE IN ASCENDING ORDER
    void insert(signed char c) {// automatically does it 256 times

         int convert1 = static_cast<int>(c + 128); //CHECKED
        //buckets[convert1]++;   << "inside that index is" << buckets[convert1]
        buckets[convert1]++; //CHECKED
        ++size_;
        //size(size_);

    
    }


	// RETURNS RAW POINTER TO THE sorted array  , CAN BE INVOKED AT ANY TIME
	const signed char* data() {
        size();
       ptr_ = new signed char[size_];

    //for(int i =0; i < numbuckets; ++i){
    //    std::cout << "Xindex is" <<  i << "bucket  # inside is" << buckets[i] <<std::endl  ;}

    //    std::cout << "Size is: " << size_ << std::endl;

        int P = 0;

		for (int low = 0; low < numbuckets; ++low) {          // loop through ALL buckets
            int Pos = 0;
             //std::cout << "index is" <<  low << "bucket  # inside is" << buckets[low] <<std::endl;
            for (int j = 0; j < buckets[low]; ++j) {        //# of times to loop through each bucket
        
                if (buckets[low] == 0) continue;
				ptr_[Pos++ + P] = static_cast<signed char>(low - 128); // puts each element into the final array
            }
            P += Pos;
		}
    
    //    if (is_sorted(ptr_, ptr_+size_)) std::cout << "Sorted" <<std::endl;
    //    else std::cout << "Na" << std::endl;

		return ptr_;
    }

	//destructor
	~sorted_sc_array() {
		delete[] ptr_;
        delete[] buckets;
	}

private:
	int size_ = 0;             // size of the array
	                           //mutable
    signed  char* ptr_;        // pointer to the array
	
    int* buckets;
    int numbuckets = 256;
    int actualnumbuckets = 255;
    int high = 128;

}; // class sorted_sc_array

#endif // A2_HPP
