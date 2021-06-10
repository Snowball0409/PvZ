#ifndef ZOMBIE_H
#define ZOMBIE_H
	
class Zombie  
{
	private:
		int hp_;
		int loc_;
		const int damage_;

	public:

		Zombie();
		~Zombie();
		void Damaged(const int damage);
		bool IsDie();
		void Move(const int offset, const int max);
		
		const int Damage();
		const int Locate();
		const int HealthPoint();

};
#endif