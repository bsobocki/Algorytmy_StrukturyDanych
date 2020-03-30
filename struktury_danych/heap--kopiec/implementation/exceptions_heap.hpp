#ifndef EXCEPTIONS_HEAP_HPP
#define EXCEPTIONS_HEAP_HPP
#include <exception>

class full_heap : public std::exception {
    virtual const char* what() const throw (){
        return "The heap is full! Unable to insert a new item!";
    }
};

class empty_heap : public std::exception {
    virtual const char* what() const throw (){
        return "The heap is empty! Unable to get an item!";
    }
};

class no_parent : public std::exception {
    virtual const char* what() const throw (){
        return "There is no parent for the node!";
    }
};

class no_child : public std::exception {
    virtual const char* what() const throw (){
        return "There is no child for the node!";
    }
};

class no_left_child : public std::exception {
    virtual const char* what() const throw (){
        return "There is no left child for the node!";
    }
};

class no_right_child : public std::exception {
    virtual const char* what() const throw (){
        return "There is no right child for the node!";
    }
};

class invalid_node_index : public std::exception {
    virtual const char* what() const throw (){
        return "Invalid node index in data!";
    }
};

#endif // EXCEPTIONS_HEAP_HPP