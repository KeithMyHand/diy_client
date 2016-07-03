#include "UITool.h"

void UITool::showMessageBox(const char* title, const char* content)
{
	auto gui = GUIMessageBox::createGUI();
	gui->setTitle(title);
	gui->setContent(content);
	SceneMan::getInstance()->getCrrentScene()->addChild(gui);
}