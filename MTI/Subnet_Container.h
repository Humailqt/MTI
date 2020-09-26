#pragma once
#include <string>
#include <list>




union Union_Ip {
	int i;
	unsigned char b[4];
};

Union_Ip Convert_String_To_Union_Ip(std::string Ip);
Union_Ip GetSubnetMask(std::string Ip);

struct Subnet_Container
{
	//Конструкторы
	Subnet_Container();
	Subnet_Container(std::string Ip);
	Subnet_Container(std::list<std::string> Subnet);

	//Методы
	bool Set_Subnet(std::string Ip);
	bool Set_Subnet(std::list<std::string> NewSubnet);

	bool Delete_Subnet(std::string Ip);

	int Checking_Entry_Ip(std::string Ip);



	std::list<std::string> Subnet;

};

Subnet_Container::Subnet_Container()
{

}
Subnet_Container::Subnet_Container(std::string Ip)
{
	this->Subnet.push_back(Ip);
}
Subnet_Container::Subnet_Container(std::list<std::string> New_Subnet)
{
	this->Subnet = New_Subnet;
}

bool Subnet_Container::Set_Subnet(std::string Ip)
{
	this->Subnet.push_back(Ip);
	return 1;
}
bool Subnet_Container::Set_Subnet(std::list<std::string>NewSubnet)
{
	this->Subnet.splice(Subnet.end(),NewSubnet);
	return 1;
}

bool Subnet_Container::Delete_Subnet(std::string Ip)
{

	for (auto it = this->Subnet.begin(); it != this->Subnet.end(); it++)
	{
		if (*it==Ip)
		{
			Subnet.erase(it);
			return 1;
		}

	}
	
	return 0;
}

int Subnet_Container::Checking_Entry_Ip(std::string Ip) 
{

	Union_Ip Subnet_Container_Ip, Subnet_Container_Mask,Checking_Entry_Ip;

	Checking_Entry_Ip = Convert_String_To_Union_Ip(Ip);


	for (auto it = this->Subnet.begin(); it != this->Subnet.end(); it++)
	{
		Subnet_Container_Mask = GetSubnetMask(*it);

		Subnet_Container_Ip = Convert_String_To_Union_Ip(*it);
		if ((Subnet_Container_Ip.i & Subnet_Container_Mask.i) == (Checking_Entry_Ip.i & Subnet_Container_Mask.i))
		{
			return 1;
		}

	}

	return -1;
}

Union_Ip Convert_String_To_Union_Ip(std::string Ip)
{
	Union_Ip Ip_b;
	std::string tmp;
	tmp.clear();
	int i = 0;
	int i_b = 0;

	for (size_t j = 0; j < 4; j++)
	{
		while (Ip[i] != '.' && Ip[i] != '\0'&& Ip[i]!='/')
		{
			tmp += Ip[i];
			i++;
		}

		Ip_b.b[i_b] = std::stoi(tmp);
		i_b++;
		i++;
		tmp.clear();

	}

	return Ip_b;
}

Union_Ip GetSubnetMask(std::string Ip)
{
	std::string tmp;
	Union_Ip mask;
	mask.i = 0;
	int i = 0;
	while (Ip[i]!='/')
	{
		i++;
	}

	i++;
	while (Ip[i] != '\0')
	{
		tmp += Ip[i];
		i++;
	}

	int n = std::stoi(tmp);
	int i_b=0;
	for (size_t i = 0; i < n; i++)
	{	
		if (i%8==0&&i!=0)
		{
			i_b++;
		}
		mask.b[i_b] >>= 1;
		mask.b[i_b] |= 128;

	}

	return mask;
}

