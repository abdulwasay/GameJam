#include "player_car.h"
#include "observer.h"

PlayerCar::PlayerCar(int number)
{
	multiplier = 0.5;
	damage = 0;
	switch(number)
	{
	case 1:
		// red car
		loadRedCar();
		break;

	case 2:
		// yellow car
		loadYellowCar();
		break;

	case 3:
		// grey car
		loadGreyCar();
		break;

	default:
		// default is red car as well
		loadRedCar();
		break;
	};

	initializeCar();
}

PlayerCar::~PlayerCar()
{
	unloadCar();
}

void PlayerCar::loadRedCar()
{
	imagesGroup = IwGetResManager() -> LoadGroup ("320x480/RedCar/_redCar.group");

	image1 = Iw2DCreateImageResource("red");
	image2 = Iw2DCreateImageResource("red2");
	image3 = Iw2DCreateImageResource("red3");
	image4 = Iw2DCreateImageResource("red4");
	image5 = Iw2DCreateImageResource("red5");
}

void PlayerCar::loadYellowCar()
{

}


void PlayerCar::loadGreyCar()
{

}

void PlayerCar::unloadCar()
{
	if ( image1 )
		delete image1;
	image1 = NULL;

	if ( image2 )
		delete image2;
	image2 = NULL;

	if ( image3 )
		delete image3;
	image3 = NULL;

	if ( image4 )
		delete image4;
	image4 = NULL;

	if ( image5 )
		delete image5;
	image5 = NULL;
}

void PlayerCar::draw()
{
	switch(damage)
	{
	case 0:
		Iw2DDrawImage(image1,CIwSVec2(m_x1,m_y1),CIwSVec2(image1->GetWidth()*multiplier,image1->GetHeight()*multiplier));
		break;

	case 1:
		Iw2DDrawImage(image2,CIwSVec2(m_x1,m_y1),CIwSVec2(image2->GetWidth()*multiplier,image2->GetHeight()*multiplier));
		break;

	case 2:
		Iw2DDrawImage(image3,CIwSVec2(m_x1,m_y1),CIwSVec2(image3->GetWidth()*multiplier,image3->GetHeight()*multiplier));
		break;

	case 3:
		Iw2DDrawImage(image4,CIwSVec2(m_x1,m_y1),CIwSVec2(image4->GetWidth()*multiplier,image4->GetHeight()*multiplier));
		break;

	case 4:
		Iw2DDrawImage(image5,CIwSVec2(m_x1,m_y1),CIwSVec2(image5->GetWidth()*multiplier,image5->GetHeight()*multiplier));
		break;

	default:
		Iw2DDrawImage(image1,CIwSVec2(m_x1,m_y1),CIwSVec2(image1->GetWidth()*multiplier,image1->GetHeight()*multiplier));
		break;
	};
}

void PlayerCar::update()
{

}

void PlayerCar::initializeCar()
{
	m_x1 = (OBSERVER->getDeviceWidth() - image1->GetWidth()*multiplier)/2;
	m_y1 = OBSERVER->getDeviceHeight() - image1->GetHeight()*multiplier;
	m_width = image1->GetWidth()*multiplier;
	m_height = image1->GetHeight()*multiplier;
	m_x2 = m_x1 + m_width;
	m_y2 = m_y1 + m_height;
}

void PlayerCar::verifySpeedBounds()
{
	if ( car_speed < 0 ) {
		
		car_speed = 0;
	} else if ( car_speed > 40 ) {
		
		car_speed = 40;
	}
}