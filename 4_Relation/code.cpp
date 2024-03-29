#include <cmath>
#include <cstdio>
#include <cstdlib>
#define MAX_DIM 100
using namespace std;
class Relation
{
private:
 int size;
 int set[MAX_DIM];
 int imageCount[MAX_DIM];
 int matrix[MAX_DIM][MAX_DIM];
 int images[MAX_DIM][MAX_DIM];
protected:
 void getSet();
 void putSet();
 void getRelation();
 void putRelation();
 int indexOf(int);
public:
 Relation();
 void display();
 bool isReflexive();
 bool isSymmetric();
 bool isAntiSymmetric();
 bool isTransitive();
};
Relation::Relation()
{
 getSet();
 getRelation();
}
void Relation::display()
{
 putSet();
 putRelation();
}
void Relation::getSet()
{
 printf("Enter Size of Set: ");
 scanf("%i", &size);
 if (size != 0)
 {
 printf("Enter Elements of Set: ");
 for (int i = 0; i < size; i++)
 scanf("%i", &set[i]);
 }
}
void Relation::putSet()
{
 printf("Set: { ");
 if (size != 0)
 {
 for (int i = 0; i < size; i++)
 printf("%i, ", set[i]);
 printf("\b\b }\n");
 }
 else
 {
 printf("}\n");
 }
}
int Relation::indexOf(int el)
{
 int i = 0;
 while (i < size)
 {
 if (set[i] == el)
 return i;
 i++;
 }
 return -1;
}
void Relation::getRelation()
{
 for (int i = 0; i < size; i++)
 {
 printf("Enter number of images for Set Element %i: ", set[i]);
 scanf("%i", &imageCount[i]);
 if (imageCount[i] != 0)
 {
 printf("Enter images of Set Element %i: ", set[i]);
 for (int j = 0; j < imageCount[i]; j++)
 {
 scanf("%i", &images[i][j]);
 if (indexOf(images[i][j]) == -1)
 {
 printf("Error: Image not in Set\n");
 i--;
 break;
 }
 else
 {
 matrix[i][indexOf(images[i][j])] = 1;
 }
 }
 }
 }
 printf("\n");
}
void Relation::putRelation()
{
 printf("Relation R:\n{ ");
 if (size != 0)
 {
 for (int i = 0; i < size; i++)
 {
 if (imageCount[i] != 0)
 printf("\n ");
 {
 for (int j = 0; j < imageCount[i]; j++)
 {
 if (i == size - 1 && j == imageCount[i] - 1)
 printf("(%i, %i)\n", set[i], images[i][j]);
 else
 printf("(%i, %i), ", set[i], images[i][j]);
 }
 }
 }
 printf("}\n");
 printf("Relation Matrix for Relation R:\n");
 for (int i = 0; i < size; i++)
 {
 for (int j = 0; j < size; j++)
 printf("%i ", matrix[i][j]);
 printf("\n");
 }
 printf("\n");
 }
 else
 {
 printf("}\n\n");
 }
}
bool Relation::isReflexive()
{
 if (size == 0)
 return false;
 for (int i = 0; i < size; i++)
 if (!matrix[i][i])
 return false;
 return true;
}
bool Relation::isSymmetric()
{
 for (int i = 0; i < size; i++)
 for (int j = 0; j < size; j++)
 if (matrix[i][j] && !matrix[j][i])
 return false;
 return true;
}
bool Relation::isAntiSymmetric()
{
 for (int i = 0; i < size; i++)
 for (int j = 0; j < size; j++)
 if (matrix[i][j] && matrix[j][i] && i != j)
 return false;
 return true;
}
bool Relation::isTransitive()
{
 for (int i = 0; i < size; i++)
 for (int j = 0; j < size; j++)
 for (int k = 0; k < size; k++)
 if (matrix[i][j] && matrix[j][k] && !matrix[i][k])
 return false;
 return true;
}
int main()
{
 Relation r;
 r.display();
 bool isEquivalent = r.isReflexive() &&
 r.isSymmetric() &&
 r.isTransitive();
 bool isPartiallyOrdered = r.isReflexive() &&
 r.isAntiSymmetric() &&
 r.isTransitive();
 printf("Relation R is %s\n",
 isEquivalent && isPartiallyOrdered ?
 "an equivalent as well as a partially-ordered relation"
 : isEquivalent ? "an equivalent relation"
 : isPartiallyOrdered ? "a partially-ordered relation"
 : "neither an equivalent nor a partially-ordered relation"
 );
 return 0;
}
