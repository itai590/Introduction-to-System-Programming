#ifndef __CHILD__
#define __CHILD__

typedef struct {
	int id;
	int age;
} Child;

#define COMPRESSED_CHILD_SIZE 2 //bytes

unsigned char* compressedChild(const Child* child);

void unCompressedChild(unsigned char* pBuffer, Child* child);

void readChild(FILE* fp, Child* pChild, int fileFormat);

void showChild(const Child* pChild);

void getChildFromUser(Child* pChild, int id);

void writeChild(FILE* fp, const Child* pChild, int fileFormat);

Child* findChildById(Child** pChildList, int count, int id) ;

void birthday(Child* pChild);

int compareChildsById(const void* st1, const void* st2);

int compareChildsById_v2(const void* st1, const void* st2);
//void	releaseChild(Child* pChild)

#endif
