/*
    Bartosz Sobocki 29.03.2020 r.
    Implementation of a heap min with constant maximum size.

    All code 
*/

#ifndef HEAP_HPP
#define HEAP_HPP
#include <algorithm>
#include "exceptions_heap.hpp"

template <class T, unsigned int max_size, class Compare = std::less<T> >
class bin_heap{
    public:
        bin_heap(): size(0) {}

        void insert(const T & elem){
            if ( size < max_size ){
                data[size++] = elem;
                go_up(size-1);
            }
            else throw full_heap();
        }
        
        T delete_min(){
            if (size>0){
                auto temp = data[0];
                data[0] = data[size-1];
                go_down(0);
                size--;
                return temp;
            }
            throw empty_heap();
        }

        // faster delete_min
        T delete_min_hole(){
            if (size>0){
                auto temp = data[0];
                auto hole_index = hole_down();
                data[hole_index] = data[size-1];
                if (hole_index != size-1)
                    go_up(hole_index);
                size--;
                return temp;
            }
            throw empty_heap();
        }
        
        T & min(){
            if (size > 0) return data[size - 1];
            throw empty_heap();
        }

        void print_heap(){
            for(int i = 0; i < size; i++)
                printf("%d  ", data[i]);
            printf("\n");
        }

        void print_node(unsigned int i){
            std::cout<<"node "<<i<<":  "<<data[i];
            std::cout<<"   left : ";
            if (is_node(left_child_index(i)))
                std::cout<<left_child(i);
            else
                std::cout<<" no child";
            std::cout<<"   right: ";
            if (is_node(right_child_index(i)))
                std::cout<<right_child(i);
            else
                std::cout<<" no child";
            std::cout<<"  parent: ";
            if (i==0)
                std::cout<<"no parent";
            else
                std::cout<<parent(i);
            std::cout<<std::endl;
        }

        void print_heap_nodes(){
            for(int i = 0; i<size; i++){
                print_node(i);
            }
        }

    private:
        bool is_root(unsigned int i) { return i == 0; }
        bool is_node(unsigned int i) { return i >= 0 && i < size; }
        bool has_child(unsigned int i) { return is_node(left_child_index(i)); }

        unsigned int parent_index(unsigned int i) { return ((i + 1) >> 1) - 1; }
        unsigned int left_child_index(unsigned int i) { return ((i + 1) << 1 ) - 1; }
        unsigned int right_child_index(unsigned int i) { return (i + 1) << 1; }
        unsigned int min_child_index(unsigned int i) { 
            if( is_node(left_child_index(i))){
                if( is_node( right_child_index(i) ) &&  compare(right_child(i), left_child(i)))
                    return right_child_index(i);
                return left_child_index(i);
            }
            throw no_child();
        }

        T & parent(unsigned int i){ 
            if (is_node(i)){
                if(is_node(parent_index(i))) 
                    return data[parent_index(i)];
                throw no_parent();
            }
            throw invalid_node_index();
        }
        T & left_child(unsigned int i){ 
            if (is_node(i)){ 
                if (is_node(left_child_index(i)))
                    return data[left_child_index(i)];
                else no_left_child();
            }
            throw invalid_node_index();
        }
        T & right_child(unsigned int i){ 
            if (is_node(i)){
                if (is_node(right_child_index(i)))
                    return data[(i + 1) << 1]; 
                throw no_right_child();
            }
            throw invalid_node_index();
        }

        void go_up(unsigned int i){
            while ( is_node(i) && !is_root(i) && is_node(parent_index(i)) && compare(data[i], parent(i)) ){
                std::swap(data[i], parent(i));
                i = parent_index(i);
            }
        }
        void go_down(unsigned int i){
            while( is_node(i) && has_child(i) ){ 
                auto mci = min_child_index(i);
                if( compare(data[mci], data[i] )){
                    std::swap(data[mci], data[i]);
                    i = mci;
                }
                else break;
            }
        }
        unsigned int hole_down(){
            // at the beggining root is a hole
            unsigned int index = 0;
            while(has_child(index)){
                auto mci = min_child_index(index);
                std::swap(data[index], data[mci]);
                index = mci; 
            }
            return index;
        }

        unsigned int size;
        Compare compare;
        T data [max_size];

};

#endif // HEAP_HPP