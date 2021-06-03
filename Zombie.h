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
		const int Damage();
		bool IsDie();
		void Move(const int loc);

};
#endif