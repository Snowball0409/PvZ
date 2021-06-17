#ifndef ZOMBIE_H
#define ZOMBIE_H

#include <iostream>
	
class Zombie  
{
	friend std::ostream &operator <<(std::ostream &os, const Zombie &zombie);

	private:
		int hp_;
		int loc_;
		const int damage_;

	public:

		Zombie();
		Zombie(int &hp, const int &damage, int &loc);
		~Zombie();
		void Damaged(const int damage);
		bool IsDie();
		void Move(const int offset, const int max);
		
		int Damage() const;
		int Locate() const;
		int HealthPoint() const;

};
#endif