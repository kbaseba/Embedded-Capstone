#define NUM_THREADS 5

void runThreads(MemoryStructure* mem_ptr);

void *imageRec(void* mem_ptr);

void *reading(void* mem_ptr);

void *toString(void* mem_ptr);

void *concatenation(void* mem_ptr);

void *audioOut(void* mem_ptr);

void *(*threadTasks[NUM_THREADS])(void*) = {imageRec, reading, toString, concatenation, audioOut};  
