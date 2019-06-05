#include <QtCore>
#include "functions.h"

bool check(QString expression)
{
    int i;
    int length = expression.length();

    if(expression[0] == '/' || expression[0] == '*' || expression[0] == '+' || expression[0] == '.' || expression[0] == ')')
        return(false);

    for(i = 0; i < length - 1; i++)
    {
        if((expression[i] == '(' && expression[i + 1] >= '*' && expression[i + 1] <= '+') || (expression[i + 1] >= '.' && expression[i + 1] <= '/'))
            return(false);
    }

    for(i = 1; i < length; i++)
    {
        if((expression[i] == ')' && expression[i - 1] >= '(' && expression[i - 1] <= '+') || (expression[i - 1] >= '-' && expression[i - 1] <= '/'))
            return(false);
    }

    for(i = 1; i < length - 1; i++)
    {
        if((expression[i] == '+' || expression[i] == '-' || expression[i] == '*' || expression[i] == '/' || expression[i] == '.')
                && (expression[i] == '+' || expression[i + 1] == '-' || expression[i + 1] == '*' || expression[i + 1] == '/' || expression[i + 1] == '.'))
            return(false);
    }

/*    int k = 0;
    bool flag;
    for(i = 1; i < length; i++)
    {
        if((expression[i] >= '0' && expression[i] <= '9') || expression[i] == '.')
            flag = true;
        else
            flag = false;
        if (expression[i] == '.')
            k++;
        if(k > 1)
            return(false);
    }
*/
    return (true);
}

int calculationOfRank(QChar a)
{
    if(a == '+' || a == '-')
        return 1;
    if(a == '*' || a == '/')
        return 2;
    if(a == '(')
        return 3;
    return -1;
}

double get_result(QString expression)
{
    int i;
    int length;
    int priorityIndex;
    int priority_rank;
    int indexOfBBracket = 0;

    while(true)
    {
        length = expression.length();
        priorityIndex = -1;
        priority_rank = -1;
        for(i = 1; i < length; i++)
        {
            if (expression[i] == '+' || expression[i] == '-' || expression[i] == '*' || expression[i] == '/')
            {
                if(calculationOfRank(expression[i]) > priority_rank)
                {
                    priorityIndex = i;
                    priority_rank = calculationOfRank(expression[i]);
                }
            }
        }

        if(priorityIndex == -1)
            return(expression.toDouble());

        int rborder, lborder;

        i = priorityIndex - 1;
        while((i >= 0) && ((expression[i] >= '0' && expression[i] <= '9') || expression[i] == '.'))
        {
            i--;
        }
        i++;
        if((i == 1) && (expression[0] =='-'))
            i = 0;
        if((i > 1) && (expression[i - 1] == '-') && (expression[i - 2] == '('))
            i--;
        lborder = i;

        i = priorityIndex + 1;
        while((i < expression.length()) && ((expression[i] >= '0' && expression[i] <= '9') || expression[i] == '.'))
        {
            i++;
        }
        i--;
        rborder = i;

        QString buffer1, buffer2, bufferRez;

        for(i = lborder; i < priorityIndex; i++)
            buffer1.push_back(expression[i]);

        for(i = priorityIndex + 1; i <= rborder; i++)
            buffer2.push_back(expression[i]);

        if(expression[priorityIndex] == '+')
            bufferRez = QString::number(buffer1.toDouble() + buffer2.toDouble(), 'g', 15);
        if(expression[priorityIndex] == '-')
            bufferRez = QString::number(buffer1.toDouble() - buffer2.toDouble(), 'g', 15);
        if(expression[priorityIndex] == '*')
            bufferRez = QString::number(buffer1.toDouble() * buffer2.toDouble(), 'g', 15);
        if(expression[priorityIndex] == '/')
            bufferRez = QString::number(buffer1.toDouble() / buffer2.toDouble(), 'g', 15);

 /*
        for(i = priorityIndex + 1; i <= length - 1; i++)
        {
            if((expression[i] < '0' || expression[i] > '9') && expression[i] != '.')
                break;
        }
        if((i == length - 1) && expression[length - 1] > '0' && expression[length - 1] < '9')
            rborder = i;
        else
            rborder = i - 1;

        i = priorityIndex - 1;
        while(i > 0)
        {
            if((expression[i] < '0' || expression[i] > '9') && expression[i] != '.')
                break;
            i--;
        }

        if(i == 1 && ((expression[0] >= '0' && expression[0] <= '9') || expression[0] == '-'))
            lborder = 0;
        if(i > 1 && expression[i - 1] == '-' && expression[i - 2] == '(')
            lborder = i;
        else
            lborder = i + 1;

        QString buffer1, buffer2, bufferRez;

        for(i = lborder; i < priorityIndex; i++)
            buffer1.push_back(expression[i]);

        for(i = priorityIndex + 1; i <= rborder; i++)
            buffer2.push_back(expression[i]);

        if(expression[priorityIndex] == '+')
            bufferRez = QString::number(buffer1.toDouble() + buffer2.toDouble(), 'g', 15);
        if(expression[priorityIndex] == '-')
            bufferRez = QString::number(buffer1.toDouble() - buffer2.toDouble(), 'g', 15);
        if(expression[priorityIndex] == '*')
            bufferRez = QString::number(buffer1.toDouble() * buffer2.toDouble(), 'g', 15);
        if(expression[priorityIndex] == '/')
            bufferRez = QString::number(buffer1.toDouble() / buffer2.toDouble(), 'g', 15);
  */

        buffer1 = "";
        buffer2 = "";

        if(lborder > 0 && (expression[lborder - 1] == '('))
            lborder--;
        if((rborder < expression.length() - 1) && (expression[rborder + 1] == ')'))
            rborder++;


        for(i = 0; i < lborder; i++)
            buffer1.push_back(expression[i]);

        for(i = rborder + 1; i < expression.length(); i++)
            buffer2.push_back(expression[i]);

        expression = buffer1 + bufferRez + buffer2;
    }
}


