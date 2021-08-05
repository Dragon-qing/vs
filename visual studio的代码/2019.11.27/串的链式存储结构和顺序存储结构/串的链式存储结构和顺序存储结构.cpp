#define maxlen 255
#define chunklen 80
typedef struct
{
	char ch[maxlen + 1];
	int length;
}sstring;//Ë³Ðò
typedef struct chunk
{
	char ch[chunklen];
	chunk*next;
}chunk;
typedef struct
{
	chunk*next, head;
	int curlen;
}lchunk;