void SeqList::Swap(int id1, int id2)
{
	type temp;
	temp = data[id1];
	data[id1] = data[id2];
	data[id2] = temp;
}
void SeqList::Replace(int id1, const Type& item)
{
	data[id1] = item;
}
SeqList& SeqList:: operator=(const SeqList& l)
{
	size = l.size;
	max = l.max;
	data = new Type[l.max];
	if (data == NULL)
	{
		exit(1);
	}
	if (max < l.size) { cout << "error!\n"; exit(1); }
	for (int i = 0; i < l.size; i++)data[i] = l.data[i];
	return*this;
}