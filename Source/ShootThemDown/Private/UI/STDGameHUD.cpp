// ShootThemDown game. All rights reserved.


#include "UI/STDGameHUD.h"
#include "Engine/Canvas.h"

void ASTDGameHUD::DrawHUD()
{
    Super::DrawHUD();

    DrawCrossHair();
}

void ASTDGameHUD::DrawCrossHair()
{
    int32 SizeX = Canvas->SizeX;
    int32 SizeY = Canvas->SizeY;

    const TInterval<float> Center(Canvas->SizeX * 0.5, Canvas->SizeY * 0.5 );

    const float HalfLineSize = 10.0f;
    const float LineThichness = 2.0f;
    const FLinearColor LineColor = FLinearColor::Green;

    DrawLine(Center.Min - HalfLineSize, Center.Max, Center.Min + HalfLineSize, Center.Max, LineColor, LineThichness );
    DrawLine(Center.Min, Center.Max - HalfLineSize, Center.Min, Center.Max + HalfLineSize, LineColor, LineThichness );
}

