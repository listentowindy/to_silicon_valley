#include<stdio.h>
#define ElemType int

typedef struct QNode{
    struct QNode *next;
    ElemType data;
}QNode, *QNodePtr;

typedef struct{
    QNode *head;
    QNode *tail;
}LinkQueue;


/*初始化一个队列*/
LinkQueue create_queue(){
    LinkQueue queue;
    QNodePtr qnode = (QNodePtr)malloc(sizeof(QNode));
    if( qnode != NULL ){
        qnode->next = NULL;
        queue.head = queue.tail = qnode;//头结点，不存数据 
        
    }
    return queue;
}

QNode *queue_search(LinkQueue *queue, ElemType key){
    QNode *p = queue->head->next;
    while( p!=NULL && p->data!=key)
        p = p->next;
    return p;
}

QNode *enqueue(LinkQueue *queue, ElemType data){
    QNode *node = (QNodePtr)malloc( sizeof(QNode) );
    if( node != NULL){
        node->data = data;
        node->next = NULL;
        queue->tail->next  = node;
        queue->tail = node;
        return node;
    }
    return NULL;
}

ElemType dequeue(LinkQueue *queue){
    QNode *node;
    ElemType dedata;//出队列的值 
    if( queue->head == queue->tail ){
        return -1;
    }
    node = queue->head->next;
    dedata = node->data;
    queue->head->next = node->next;
    if( queue->tail == node){
        queue->tail = queue->head;
    }
    free( node );
    return dedata;
}

void print_queue(LinkQueue *queue){
    QNode * p = queue->head->next;
    while( p!=NULL ){
        printf("%d ", p->data);
        p = p->next;
    }
    printf("\n");
}
main(){
    LinkQueue queue = create_queue();
    QNode *node;
    enqueue(&queue, 1);
    enqueue(&queue, 2);
    enqueue(&queue, 3);
    enqueue(&queue, 4);
    enqueue(&queue, 5);
    enqueue(&queue, 6);
    
    print_queue( &queue );
    
    dequeue(&queue);
    dequeue(&queue);
    
    print_queue( &queue );
     
    enqueue(&queue, 5);
    enqueue(&queue, 6);
    
    print_queue( &queue );
    
    node = queue_search( &queue, 3);
    printf("---%d----", node->data);
    system("pause");
}
