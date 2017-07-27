/*
 * SGF ���� Simple Graphics Frame
 */

#include "sgfwin.h"
#include "sgferr.h"
#include "sgfd2drender.h"

int WINAPI WinMain(
	HINSTANCE hInstance/* hInstance */,
	HINSTANCE /* hPrevInstance */,
	LPSTR /* lpCmdLine */,
	int /* nCmdShow */
)
{
	// Use HeapSetInformation to specify that the process should
	// terminate if the heap manager detects an error in any heap used
	// by the process.
	// The return value is ignored, because we want to continue running in the
	// unlikely event that HeapSetInformation fails.
	HeapSetInformation(NULL, HeapEnableTerminationOnCorruption, NULL, 0);

	SGF::D2DRender* render = new SGF::D2DRender();
	SGF::WinApp app(hInstance);

	if (app.Initialize(render) == SGF::ERR_NONE)
	{
		app.Run();
	}


	if (render)
	{
		delete render;
		render = NULL;
	}

	return 0;
}