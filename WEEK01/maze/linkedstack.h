#ifndef _LINKED_STACK_
#define _LINKED_STACK_

typedef struct s_pos
{
	int x;
	int y;
}t_pos;

typedef struct StackNodeType
{
	t_pos data;
	struct StackNodeType* pLink;
} StackNode;

typedef struct LinkedStackType
{
	int currentElementCount;
	StackNode* pTopElement;
} LinkedStack;

#define HEIGHT		8
#define WIDTH		8


LinkedStack* createLinkedStack();
int pushLS(LinkedStack* pStack, t_pos element);
StackNode* popLS(LinkedStack* pStack);
StackNode* peekLS(LinkedStack* pStack);
void deleteLinkedStack(LinkedStack* pStack);
int isLinkedStackEmpty(LinkedStack* pStack);

void displayLinkedStack(LinkedStack *pStack);

void	printMap(void);
int		poscmp(const t_pos a, const t_pos b);
int		pos_in_map(const t_pos pos);

int		findPath(const t_pos startPos, const t_pos endPos, LinkedStack *pStack);

#endif

#ifndef _COMMON_STACK_DEF_
#define _COMMON_STACK_DEF_

#define TRUE		1
#define FALSE		0

#endif