#include "Exec.h"
void Exec::exec(Poliz &prog, Table_Ident &TID)
{
	Stack<int> args;
	int i, j, index = 0, size = prog.get_free();
	while (index < size)
	{
		//args.out();
		elem = prog[index];
		switch (elem.get_type())
		{
			case LEX_TRUE:
			case LEX_FALSE:
			case LEX_NUM:
			case POLIZ_ADDRESS:
			case POLIZ_LABEL:
				args.push(elem.get_value_int());
				break;
			case LEX_CONST_STRING:
				//TODO
				break;
			case LEX_ID:
				i = elem.get_value_int();
				if (TID[i].get_assign())
				{
					if (TID[i].get_type() == LEX_INT or TID[i].get_type() == LEX_BOOL)
					{
						args.push(TID[i].get_value());
					}
					else
					{
						//TODO
					}
				}
				break;
			case LEX_NOT:
				args.push(!args.pop());
				break;
			case LEX_OR:
				i = args.pop();
				args.push(args.pop() || i);
				break;
			case LEX_AND:
				i = args.pop();
				args.push(args.pop() && i);
				break;
			case POLIZ_GO:
				index = args.pop() - 1;
				break;
			case POLIZ_CONDITION_GO:
				i = args.pop();
				if (!args.pop())
				{
					index = i - 1;
				}
				break;
			case POLIZ_POP:
				//TODO???
				break;
			case LEX_WRITE:
				std::cout << args.pop() << std::endl;
				break;
			case LEX_READ:
				//TODO
				break;
			case LEX_PLUS:
				//TODO also for int
				args.push(args.pop() + args.pop());
				break;
			case LEX_MINUS:
				args.push(args.pop() - args.pop());
				break;	
			case LEX_TIMES:
				args.push(args.pop() * args.pop());
				break;	
			case LEX_SLASH:
				args.push(args.pop() / args.pop());
				//TODO except
				break;	
			case LEX_PERCENT:
				args.push(args.pop() % args.pop());
				//TODO except
				break;	
			case LEX_EQ:
				//TODO also for int
				args.push(args.pop() == args.pop());
				break;	
			case LEX_LSS:
				//TODO
				break;	
			case LEX_GTR:
				//TODO
				break;	
			case LEX_LEQ:
				i = args.pop();
				args.push(args.pop() <= i);
				break;	
			case LEX_GEQ:
				i = args.pop();
				args.push(args.pop() >= i);
				break;	
			case LEX_NEQ:
				//TODO
				break;	
			case LEX_ASSIGN:
				i = args.pop();
				j = args.pop();
				//TODO this is also for int
				TID[j].put_value(i);
				TID[j].put_assign();
				args.push(i);
				break;	
		}
		++index;
	}
}
