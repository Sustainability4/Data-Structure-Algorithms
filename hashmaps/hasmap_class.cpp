#include <iostream>
using namespace std;

template<typename V>
class mapnode{
    public:
    string key;
    V value;
    mapnode*next;

    mapnode(string key, V value){
        this->key = key;
        this->value = value;
        next = NULL;
    }

    ~mapnode(){
        delete next;
    }
};

template<typename V>
class ourmap{
    mapnode<V>**buckets;
    int size;
    int numbuckets;

    public:
    ourmap(){
        size = 0;
        numbuckets = 5;
        buckets = new mapnode<V>*[numbuckets];

        for(int i = 0; i<numbuckets; i++){
            buckets[i] = NULL;
        }
    }

    ~ourmap(){
        for(int i =0 ; i<numbuckets; i++){
            delete buckets[i];
        }

        delete [] buckets;
    }

    int size(){
        return count;
    }

    V getvalue(string key){
         int bucketIndex = getbucketIndex(string key);
         mapnode<V>*head = buckets[bucketIndex];
         while(head != NULL){
            if(head->key == key){
                return head->value; 
            }
            head = head->next;
        }

        return 0;

    }
    private:
    int getbucketIndex(string key){
        int hashcode = 0;
        int currentcoefficient = 1;

        for(int i = key.length(); i>=0; i--){
            hashcode += key[i]*currentcoefficient;
            hashcode = hashcode%numbuckets;
            currentcoefficient *= 37;
            currentcoefficient = currentcoefficient%numbuckets;
        } 

        return hashcode%numbuckets;
    }
    
    void rehash(){
        mapnode<V>**temp = buckets;
        buckets = new mapnode<V>*[2*numbuckets];
        for(int i = 0 ; i<2*numbuckets; i++){
            buckets[i] = NULL;
        }
        
        int oldbucketcount = numbuckets;
        numbuckets *= 2;
        count = 0;
        
        for(int i =0 ; i<oldbucketcount;i++){
            mapnode<V>*head = temp[i];
            while(head != NULL){
                string key = head->key;
                V value = head->value;
                insert(key,head);
                head = head->next;
           }
        }
        
        for(int i = 0 ; i<oldbucketcount; i++){
            mapnode<V>*head = temp[i];
            delete head;
        }
        
        delete [] temp;
    }

    public:

    void insert(string key, V value){
        int bucketIndex = getbucketIndex(string key);
        mapnode<V>*head = buckets[bucketIndex];
        while(head != NULL){
            if(head->key == key){
                head->value = value;
                return;
            }
            head = head->next;
        }

        head = buckets[bucketIndex];
        mapnode<V>*node = new mapnode<V>(key, value);
        node->next = head;
        buckets[bucketIndex] = node;
        count++;
        
        double load_factor = (1+count)/numbuckets;
        if(load_factor >0.7){
            rehash();
        }


    }

    V remove(string key){
        int bucketIndex = getbucketIndex(string key);
        mapnode<V>*head = buckets[bucketIndex];
        mapnode<V>*prev = NULL;
        while(head != NULL){
            if(head->key == key){
                if(prev == NULL){
                    buckets[bucketIndex] = head->next;
                }else {
                    prev->next = head->next;
                }

                V value = head->value;
                head->next = NULL;
                delete head;
                return value;
                
            }
            prev = head;
            head = head->next;
        }

        return 0;
    }
};
int main() {
    cout<<"Hello World!";
}
