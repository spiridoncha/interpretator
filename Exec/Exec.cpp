#include "Exec.h"
void Exec::exec(Poliz &prog, Table_Ident &TID)
{
	Stack<Lex> args;
	Stack<Lex> write;
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
				if (!TID[id].get_assign())
				{
					TID[id].put_value(0);
					TID[id].put_value(String(""));
				}
				i = Lex(LEX_NULL, TID[id].get_value());
				i = i.put_value(TID[id].get_value_str());
				if (TID[id].get_type() == LEX_STRING)
				{
					args.push(i.put_type(LEX_CONST_STRING));
				}
				else if (TID[id].get_type() == LEX_INT)
				{
					args.push(i.put_type(LEX_NUM));
				}
				else
				{
					args.push(i.put_type(LEX_BOOL));
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
				i = args.pop();
				index = i.get_value_int() - 1;
				break;
			case POLIZ_CONDITION_GO:
				i = args.pop();
				if (!args.pop().get_value_int())
				{
					index = i.get_value_int() - 1;
				}
				break;
			case POLIZ_SEQ_WRITE:
				write.push(args.pop());
				write.push(args.pop());
				break;
			case POLIZ_POP:
				i = args.pop();
				break;
			case LEX_WRITE:
				if (write.is_Empty())
				{
					write.push(args.pop());
				}
				while (!write.is_Empty())
				{
					i = write.pop();
					switch (i.get_type())
					{
						case LEX_NUM:
							std::cout << i.get_value_int() << std::endl;
							break;
						case LEX_TRUE:
							std::cout << "true" << std::endl;
							break;
						case LEX_FALSE:
							std::cout << "false" << std::endl;
							break;
						case LEX_CONST_STRING:
							std::cout << i.get_value_str() << std::endl;
							break;
						case LEX_BOOL:
							std::cout << String(i.get_value_int() ? "true" : "false") << std::endl;
							break;
						case LEX_ID:
							break;
						default:
							std::cout << "lal" << std::endl;
							break;
					}
				}
				break;
			case LEX_READ:
				//TODO
				int c;
				i = args.pop();
				id = i.get_value_int();
				if (TID[id].get_type() == LEX_INT)
				{
					int val;
					std::cin >> val;
					TID[id].put_assign();
					TID[id].put_value(val);
				}
				else
				{
					Buffer buf;
					buf.clear();
					while (((c = getchar()) != '\n') && (c != EOF))
					{
						buf.add(c);
					}
					TID[id].put_assign();
					TID[id].put_value(String(buf()));
				}
				break;
			case LEX_PLUS:
				i = args.pop();
				j = args.pop();
				if (i.get_type() == LEX_CONST_STRING)
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
				i = args.pop();
				j = args.pop();
				if (i.get_type() == LEX_CONST_STRING)
				{
					args.push(Lex(LEX_BOOL, j.get_value_str() == i.get_value_str()));
				}
				else
				{
					args.push(Lex(LEX_BOOL, j.get_value_int() == i.get_value_int()));
				}
				break;	
			case LEX_LSS:
				i = args.pop();
				j = args.pop();
				if (i.get_type() == LEX_CONST_STRING)
				{
					args.push(Lex(LEX_BOOL, j.get_value_str() < i.get_value_str()));
				}
				else
				{
					args.push(Lex(LEX_BOOL, j.get_value_int() < i.get_value_int()));
				}
				break;	
			case LEX_GTR:
				i = args.pop();
				j = args.pop();
				if (i.get_type() == LEX_CONST_STRING)
				{
					args.push(Lex(LEX_BOOL, j.get_value_str() > i.get_value_str()));
				}
				else
				{
					args.push(Lex(LEX_BOOL, j.get_value_int() > i.get_value_int()));
				}
				break;	
			case LEX_LEQ:
				i = args.pop();
				j = args.pop();
				args.push(Lex(LEX_BOOL, j.get_value_int() <= i.get_value_int()));
				break;	
			case LEX_GEQ:
				i = args.pop();
				j = args.pop();
				args.push(Lex(LEX_BOOL, j.get_value_int() >= i.get_value_int()));
				break;	
			case LEX_NEQ:
				i = args.pop();
				j = args.pop();
				if (i.get_type() == LEX_CONST_STRING)
				{
					args.push(Lex(LEX_BOOL, j.get_value_str() != i.get_value_str()));
				}
				else
				{
					args.push(Lex(LEX_BOOL, j.get_value_int() != i.get_value_int()));
				}
				break;	
			case LEX_ASSIGN:
				i = args.pop();
				j = args.pop();
				TID[j.get_value_int()].put_value(i.get_value_int());
				TID[j.get_value_int()].put_value(i.get_value_str());
				TID[j.get_value_int()].put_assign();
				args.push(i);
				break;	
			default:
				break;
		}
		++index;
	}
}
