#include "AppDelegate.h"
#include "Man\SceneMan.h"
USING_NS_CC;

#define WINDOW_DEFAULT_HEIGHT 1280
#define WINDOW_DEFAULT_WIDTH 760

AppDelegate::AppDelegate() 
{
	m_pAppGame = new AppGame();
}

AppDelegate::~AppDelegate() 
{
}

//if you want a different context,just modify the value of glContextAttrs
//it will takes effect on all platforms
void AppDelegate::initGLContextAttrs()
{
    //set OpenGL context attributions,now can only set six attributions:
    //red,green,blue,alpha,depth,stencil
    GLContextAttrs glContextAttrs = {8, 8, 8, 8, 24, 8};

    GLView::setGLContextAttrs(glContextAttrs);
}

// If you want to use packages manager to install more packages, 
// don't modify or remove this function
static int register_all_packages()
{
    return 0; //flag for packages manager
}

bool AppDelegate::applicationDidFinishLaunching() 
{
	int winWidth = WINDOW_DEFAULT_WIDTH / 2;
	int winHeight = WINDOW_DEFAULT_HEIGHT / 2;

    // initialize director
    auto director = Director::getInstance();
    auto glview = director->getOpenGLView();
	if (!glview) 
	{
		char* winName = new char[32];
		sprintf(winName, "DIY   WinSize: %d * %d", winWidth, winHeight);
		glview = GLViewImpl::create(winName);
        director->setOpenGLView(glview);
    }
    // turn on display FPS
    director->setDisplayStats(false);

    // set FPS. the default value is 1.0/60 if you don't call this
	director->setAnimationInterval(1.0 / 30);
#if (CC_TARGET_PLATFORM == CC_PLATFORM_WIN32)
	glview->setFrameSize(winWidth, winHeight);
#endif
    // Set the design resolution
	glview->setDesignResolutionSize(WINDOW_DEFAULT_WIDTH, WINDOW_DEFAULT_HEIGHT, ResolutionPolicy::EXACT_FIT);

	register_all_packages();

	m_pAppGame->onInit();

	SceneMan::getInstance()->pushScene("GameScene");

    return true;
}

// This function will be called when the app is inactive. When comes a phone call,it's be invoked too
void AppDelegate::applicationDidEnterBackground() 
{
    Director::getInstance()->stopAnimation();

    // if you use SimpleAudioEngine, it must be pause
    // SimpleAudioEngine::getInstance()->pauseBackgroundMusic();
}

// this function will be called when the app is active again
void AppDelegate::applicationWillEnterForeground() 
{
    Director::getInstance()->startAnimation();

    // if you use SimpleAudioEngine, it must resume here
    // SimpleAudioEngine::getInstance()->resumeBackgroundMusic();
}
