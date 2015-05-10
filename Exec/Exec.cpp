#include "Exec.h"
void Exec::exec(Poliz &prog, Table_Ident &TID)
{
	Stack<Lex> args;
	int index = 0, size = prog.get_free(), id;
	Lex i, j;
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
			case LEX_CONST_STRING:
				args.push(elem);
				break;
			case LEX_ID:
				id = elem.get_value_int();
				if (TID[id].get_assign())
				{
					args.push(elem);
				}
				break;
			case LEX_NOT:
				i = args.pop();
				args.push(i.put_value(!(i.get_value_int())));
				break;
			case LEX_OR:
				i = args.pop();
				j = args.pop();
				args.push(j.put_value(j.get_value_int() || i.get_value_int()));
				break;
			case LEX_AND:
				i = args.pop();
				j = args.pop();
				args.push(j.put_value(j.get_value_int() && i.get_value_int()));
				break;
			case POLIZ_GO:
				index = args.pop().get_value_int() - 1;
				break;
			case POLIZ_CONDITION_GO:
				i = args.pop();
				if (!args.pop().get_value_int())
				{
					index = i.get_value_int() - 1;
				}
				break;
			case POLIZ_POP:
				//TODO???
				break;
			case LEX_WRITE:
				i = args.pop();
				switch (i.get_type())
				{
					case LEX_INT:
						std::cout << i.get_value_int() << std::endl;
						break;
					case LEX_BOOL:
						if (i.get_value_int())
						{
							std::cout << "True" << std::endl;
						}
						else
						{
							std::cout << "False" << std::endl;
						}
						break;
					case LEX_STRING:
						std::cout << i.get_value_str() << std::endl;
						break;
					default:
						break;
				}
				break;
			case LEX_READ:
				//TODO
				break;
			case LEX_PLUS:
				//TODO also for int
				i = args.pop();
				j = args.pop();
				if (i.get_type() == LEX_STRING)
				{
					args.push(j.put_value(j.get_value_str() + i.get_value_str()));
				}
				else
				{
					args.push(j.put_value(j.get_value_int() + i.get_value_int()));
				}
				break;
			case LEX_MINUS:
				i = args.pop();
				j = args.pop();
				args.push(j.put_value(j.get_value_int() - i.get_value_int()));
				break;	
			case LEX_TIMES:
				i = args.pop();
				j = args.pop();
				args.push(j.put_value(j.get_value_int() * i.get_value_int()));
				break;	
			case LEX_SLASH:
				//TODO
				i = args.pop();
				j = args.pop();
				args.push(j.put_value(j.get_value_int() / i.get_value_int()));
				break;	
			case LEX_PERCENT:
				//TODO
				i = args.pop();
				j = args.pop();
				args.push(j.put_value(j.get_value_int() % i.get_value_int()));
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
			default:
				break;
		}
		++index;
	}
}
