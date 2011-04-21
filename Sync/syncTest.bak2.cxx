/*=========================================================================

  Program:   Visualization Toolkit
  Module:    Cone.cxx

  Copyright (c) Ken Martin, Will Schroeder, Bill Lorensen
  All rights reserved.
  See Copyright.txt or http://www.kitware.com/Copyright.htm for details.

     This software is distributed WITHOUT ANY WARRANTY; without even
     the implied warranty of MERCHANTABILITY or FITNESS FOR A PARTICULAR
     PURPOSE.  See the above copyright notice for more information.

=========================================================================*/
//
// This example creates a polygonal model of a cone, and then renders it to
// the screen. It will rotate the cone 360 degrees and then exit. The basic
// setup of source -> mapper -> actor -> renderer -> renderwindow is 
// typical of most VTK programs.
//

// First include the required header files for the VTK classes we are using.
#include "vtkConeSource.h"
#include "vtkPolyDataMapper.h"
#include "vtkRenderWindow.h"
#include "vtkCamera.h"
#include "vtkActor.h"
#include "vtkRenderer.h"
#include "vtkInteractorStyleTrackballCamera.h"
#include "vtkRenderWindowInteractor.h"

int main()
{
  // 
  // Next we create an instance of vtkConeSource and set some of its
  // properties. The instance of vtkConeSource "cone" is part of a
  // visualization pipeline (it is a source process object); it produces data
  // (output type is vtkPolyData) which other filters may process.
  //
  vtkConeSource *cone = vtkConeSource::New();
  cone->SetHeight( 3.0 );
  cone->SetRadius( 1.0 );
  cone->SetResolution( 10 );

  vtkConeSource *cone2 = vtkConeSource::New();
  cone2->SetHeight( 3.0 );
  cone2->SetRadius( 1.0 );
  cone2->SetResolution( 10 );
  
  // 
  // In this example we terminate the pipeline with a mapper process object.
  // (Intermediate filters such as vtkShrinkPolyData could be inserted in
  // between the source and the mapper.)  We create an instance of
  // vtkPolyDataMapper to map the polygonal data into graphics primitives. We
  // connect the output of the cone souece to the input of this mapper.
  //
  vtkPolyDataMapper *coneMapper = vtkPolyDataMapper::New();
  coneMapper->SetInputConnection( cone->GetOutputPort() );

  vtkPolyDataMapper *coneMapper2 = vtkPolyDataMapper::New();
  coneMapper2->SetInputConnection( cone2->GetOutputPort() );

  // 
  // Create an actor to represent the cone. The actor orchestrates rendering
  // of the mapper's graphics primitives. An actor also refers to properties
  // via a vtkProperty instance, and includes an internal transformation
  // matrix. We set this actor's mapper to be coneMapper which we created
  // above.
  //
  vtkActor *coneActor = vtkActor::New();
  coneActor->SetMapper( coneMapper );

  vtkActor *coneActor2 = vtkActor::New();
  coneActor2->SetMapper( coneMapper2 );

  //
  // Create the Renderer and assign actors to it. A renderer is like a
  // viewport. It is part or all of a window on the screen and it is
  // responsible for drawing the actors it has.  We also set the background
  // color here.
  //
  vtkRenderer *ren1= vtkRenderer::New();
  ren1->AddActor( coneActor );
  ren1->SetBackground( 0.0, 0.5, 1.0 );

  vtkRenderer *ren2= vtkRenderer::New();
  ren2->AddActor( coneActor2 );
  ren2->SetBackground( 1.0, 0.5, 0.0 );

  //
  // Finally we create the render window which will show up on the screen.
  // We put our renderer into the render window using AddRenderer. We also
  // set the size to be 300 pixels by 300.
  //
  vtkRenderWindow *renWin = vtkRenderWindow::New();
  renWin->AddRenderer( ren1 );
  renWin->SetSize( 200, 200 );

  vtkRenderWindow *renWin2 = vtkRenderWindow::New();
  renWin2->AddRenderer( ren2 );
  renWin2->SetSize( 200, 200 );

  //Create Interactor
  vtkRenderWindowInteractor *iren = vtkRenderWindowInteractor::New();
  iren->SetRenderWindow(renWin);

  vtkRenderWindowInteractor *iren2 = vtkRenderWindowInteractor::New();
  iren2->SetRenderWindow(renWin2);

  //Create style?
  vtkInteractorStyleTrackballCamera *style = vtkInteractorStyleTrackballCamera::New();
  iren->SetInteractorStyle(style);

  vtkInteractorStyleTrackballCamera *style2 = vtkInteractorStyleTrackballCamera::New();
  iren2->SetInteractorStyle(style2);

  iren->Initialize();
  iren->Start();

  iren2->Initialize();
  iren2->Start();

  //Synch Windows
  //ren1->ResetCamera();
  //ren2->ResetCamera();
  //ren2->SetActiveCamera(ren1->GetActiveCamera());

  //
  // Now we loop over 360 degreeees and render the cone each time.
  //
  //int i;
  //for (i = 0; i < 360; ++i)
  //  {
    // render the image
   // renWin->Render();
   // renWin2->Render();

    // rotate the active camera by one degree
   // ren1->GetActiveCamera()->Azimuth( 1 );
   // ren2->GetActiveCamera()->Azimuth( 2 );
   // }
  
  //
  // Free up any objects we created. All instances in VTK are deleted by
  // using the Delete() method.
  //
  cone->Delete();
  coneMapper->Delete();
  coneActor->Delete();
  ren1->Delete();
  renWin->Delete();

  cone2->Delete();
  coneMapper2->Delete();
  coneActor2->Delete();
  ren2->Delete();
  renWin2->Delete();

  return 0;
}


