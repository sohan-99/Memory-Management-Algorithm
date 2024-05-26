#include <bits/stdc++.h>
using namespace std;
void worstFit(int blockSize[], int m, int processSize[], int n)
{
  int allocation[n];
  memset(allocation, -1, sizeof(allocation));
  for (int i = 0; i < n; i++)
  {
    int wstIdx = -1;
    for (int j = 0; j < m; j++)
    {
      if (blockSize[j] >= processSize[i])
      {
        if (wstIdx == -1)
          wstIdx = j;
        else if (blockSize[wstIdx] < blockSize[j])
          wstIdx = j;
      }
    }
    if (wstIdx != -1)
    {
      allocation[i] = wstIdx;
      blockSize[wstIdx] -= processSize[i];
    }
  }
  cout << "\nProcess No.\tProcess Size\tBlock no.\n";
  for (int i = 0; i < n; i++)
  {
    cout << " " << i + 1 << "\t\t" << processSize[i] << "\t\t";
    if (allocation[i] != -1)
      cout << allocation[i] + 1;
    else
      cout << "Not Allocated";
    cout << endl;
  }
}
int main()
{
  int m, n;
  cout << "Enter number of blocks: ";
  cin >> m;
  int blockSize[m];
  cout << "Enter block sizes: ";
  for (int i = 0; i < m; ++i)
    cin >> blockSize[i];
  cout << "Enter number of processes: ";
  cin >> n;
  int processSize[n];
  cout << "Enter process sizes: ";
  for (int i = 0; i < n; ++i)
    cin >> processSize[i];
  worstFit(blockSize, m, processSize, n);
  return 0;
}
