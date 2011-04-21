#include "vtkConeSource.h"
#include "vtkCubeSource.h"
#include "vtkCylinderSource.h"
#include "vtkActor.h"
#include "vtkRenderer.h"
#include "vtkRendererCollection.h"
#include "vtkRenderWindow.h"
#include "vtkCamera.h"
#include "vtkRenderWindowInteractor.h"
#include "vtkCommand.h"
#include "vtkCallbackCommand.h"
#include "vtkPolyData.h"
#include "vtkPolyDataMapper.h"
#include "vtkSmartPointer.h"
#include "vtkInteractorStyleSwitch.h"
#include <string>
#include <vector>

using namespace std;


class SyncGroup : public vtkCommand
{
	private:
		//Attributes
		string sync_group_name_;
		vector<vtkRenderWindow*> sync_group;


	public:
		//Constructor
		static SyncGroup *New()
		{
			return new SyncGroup;
		}

		//Add render to group
		void AddRenderWindowToSyncGroup(vtkRenderWindow *renwin)
		{
			sync_group.push_back(renwin);
		}

		//After a change detected update
		virtual void Execute(vtkObject *caller, unsigned long, void*)
		{
			//Detect the camera changed
			vtkCamera *camera = static_cast<vtkCamera*>(caller);

			//Update the camera for all visualizations
			int i;
			vtkSmartPointer<vtkRenderer> ren;
			vtkSmartPointer<vtkRenderWindow> renwin;
			vtkSmartPointer<vtkRendererCollection> rens;
		
			//While loop updating all models goes here.
			for(i=0; i<sync_group.size(); i++)
			{
				ren = vtkSmartPointer<vtkRenderer>::New();
				renwin = vtkSmartPointer<vtkRenderWindow>::New();
				rens = vtkSmartPointer<vtkRendererCollection>::New();
				
				renwin = sync_group[i];
				rens = renwin->GetRenderers();
				ren = rens->GetFirstRenderer();
				ren->SetActiveCamera(camera);
				renwin->Render();
			}
		}

};

int main( int argc, char *argv[] )
{
	//Create some visualizations
	static vtkSmartPointer<vtkRenderer> renderer01;
	static vtkSmartPointer<vtkRenderer> renderer02;
	static vtkSmartPointer<vtkRenderer> renderer03;
	
	static vtkSmartPointer<vtkRenderWindow> renderWindow01;
	static vtkSmartPointer<vtkRenderWindow> renderWindow02;
	static vtkSmartPointer<vtkRenderWindow> renderWindow03;

	//MODELS

	//Cone
	vtkSmartPointer<vtkConeSource> cone =
		vtkSmartPointer<vtkConeSource>::New();

	cone->SetResolution(5);
	cone->Update();

	vtkSmartPointer<vtkPolyDataMapper> coneMapper =
		vtkSmartPointer<vtkPolyDataMapper>::New();
	coneMapper->SetInput( cone->GetOutput() );


	//Cube
	vtkSmartPointer<vtkCubeSource> cube =
		vtkSmartPointer<vtkCubeSource>::New();

	vtkSmartPointer<vtkPolyDataMapper> cubeMapper =
		vtkSmartPointer<vtkPolyDataMapper>::New();
	cubeMapper->SetInput( cube->GetOutput() );

	cubeMapper->Update();


	//Cylinder
	vtkSmartPointer<vtkCylinderSource> cylinder =
		vtkSmartPointer<vtkCylinderSource>::New();

	vtkSmartPointer<vtkPolyDataMapper> cylinderMapper =
		vtkSmartPointer<vtkPolyDataMapper>::New();
	cylinderMapper->SetInput( cylinder->GetOutput() );


	// ACTORS

	//Cone
	vtkSmartPointer<vtkActor> coneActor =
		vtkSmartPointer<vtkActor>::New();

	coneActor->SetMapper( coneMapper );


	//Cube
	vtkSmartPointer<vtkActor> cubeActor =
		vtkSmartPointer<vtkActor>::New();

	cubeActor->SetMapper( cubeMapper );


	//Cylinder
	vtkSmartPointer<vtkActor> cylinderActor =
		vtkSmartPointer<vtkActor>::New();

	cylinderActor->SetMapper( cylinderMapper );

	// RENDERER 

	renderer01= vtkSmartPointer<vtkRenderer>::New();
	renderer02= vtkSmartPointer<vtkRenderer>::New();
	renderer03= vtkSmartPointer<vtkRenderer>::New();

	renderer01->AddActor(coneActor);         
	renderer02->AddActor(cubeActor);
	renderer03->AddActor(cylinderActor);


	// RENDER-WINDOW

	renderWindow01 = vtkSmartPointer<vtkRenderWindow>::New();

	//Interaction with the model (cone)
	vtkSmartPointer<vtkRenderWindowInteractor> windowInteractor01 =
		vtkSmartPointer<vtkRenderWindowInteractor>::New();

	vtkSmartPointer<vtkInteractorStyleSwitch> trackballStyle =
		vtkSmartPointer<vtkInteractorStyleSwitch>::New();

	trackballStyle->SetCurrentStyleToTrackballCamera();

	windowInteractor01->SetInteractorStyle(trackballStyle);

	windowInteractor01->SetRenderWindow(renderWindow01);

	renderWindow01->AddRenderer(renderer01);



	renderWindow02 = vtkSmartPointer<vtkRenderWindow>::New();

	//Interaction with the model (cube)
	vtkSmartPointer<vtkRenderWindowInteractor> windowInteractor02 =
		vtkSmartPointer<vtkRenderWindowInteractor>::New();

	vtkSmartPointer<vtkInteractorStyleSwitch> trackballStyle02 =
		vtkSmartPointer<vtkInteractorStyleSwitch>::New();

	trackballStyle02->SetCurrentStyleToTrackballCamera();

	windowInteractor02->SetInteractorStyle(trackballStyle02);

	windowInteractor02->SetRenderWindow(renderWindow02);

	renderWindow02->AddRenderer(renderer02);



	renderWindow03 = vtkSmartPointer<vtkRenderWindow>::New();

	//Interaction with the model (cylinder)
	vtkSmartPointer<vtkRenderWindowInteractor> windowInteractor03 =
		vtkSmartPointer<vtkRenderWindowInteractor>::New();

	vtkSmartPointer<vtkInteractorStyleSwitch> trackballStyle03 =
		vtkSmartPointer<vtkInteractorStyleSwitch>::New();

	trackballStyle03->SetCurrentStyleToTrackballCamera();

	windowInteractor03->SetInteractorStyle(trackballStyle03);

	windowInteractor03->SetRenderWindow(renderWindow03);

	renderWindow03->AddRenderer(renderer03);

	//At some point start the visualization of models
	windowInteractor01->Initialize();
	windowInteractor02->Initialize();
	windowInteractor03->Initialize();

	//THIS PART IS IMPORTANT
	//At some point the user creates a Sync Group
	//Synch Group
	vtkSmartPointer<SyncGroup> group =
		vtkSmartPointer<SyncGroup>::New();

	//User event handling
	//Catch camera event   
	//Add to visualizations to synchronization group
	group->AddRenderWindowToSyncGroup(renderWindow01);
	group->AddRenderWindowToSyncGroup(renderWindow02);
	group->AddRenderWindowToSyncGroup(renderWindow03);

	renderer01->GetActiveCamera()->AddObserver(vtkCommand::ModifiedEvent,
		group);

	renderer01->ResetCamera();



	windowInteractor01->Start();
	windowInteractor02->Start();
	windowInteractor03->Start();

      return 0;
}


