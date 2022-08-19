Node *temp = head;
deque<int> d;
while (temp != NULL)
{
    d.push_back(temp->data);
    temp = temp->next;
}
int i = 0;
temp = head;
while (!d.empty())
{
    if (i % 2 == 1)
    {
        temp->data = d.front();
        d.pop_front();
    }
    else
    {
        temp->data = d.back();
        d.pop_back();
    }
    i++;
    temp = temp->next;
return head;