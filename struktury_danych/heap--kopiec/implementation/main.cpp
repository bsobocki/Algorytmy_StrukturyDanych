#include <iostream>
#include <random>
#include <memory>
#include <exception>
#include "heap.hpp"
#include "exceptions_heap.hpp"

int main(){
    auto heap = std::make_unique<bin_heap_min<int, 15>> ();
    std::default_random_engine generator;
    std::uniform_int_distribution<int> distribution(1,119);
    int dice_roll = distribution(generator);

    try{
        for(int i=0; i<15; i++){
            auto x = distribution(generator);
            heap->insert( x );
            std::cout<<"heap after insert "<<x<<" : "; heap->print_heap();
            std::cout<<std::endl;
        }
    }
    catch( std::exception & e){
        std::cout<<e.what()<<std::endl<<std::endl;
    }

    heap->print_heap_nodes();


    printf("\n\nheap: ");
    heap->print_heap();

    printf("delete_min: %d\n", heap->delete_min());

    printf("heap: ");
    heap->print_heap();

    printf("delete_min: %d\n", heap->delete_min());

    printf("heap: ");
    heap->print_heap();

    return 0;
}