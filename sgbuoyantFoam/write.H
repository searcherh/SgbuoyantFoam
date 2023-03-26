    if (runTime.writeTime())
    {
	volScalarField Ux (U.component(vector::X));

	volScalarField Uy (U.component(vector::Y));

	volScalarField Uz (U.component(vector::Z));

	volVectorField gradUx (fvc::grad(Ux));

	volVectorField gradUy (fvc::grad(Uy));

	volVectorField gradUz (fvc::grad(Uz));

	volScalarField Uxx (gradUx.component(vector::X));
	volScalarField Uxy (gradUx.component(vector::Y));
	volScalarField Uxz (gradUx.component(vector::Z));

	volScalarField Uyx (gradUy.component(vector::X));
	volScalarField Uyy (gradUy.component(vector::Y));
	volScalarField Uyz (gradUy.component(vector::Z));

	volScalarField Uzx (gradUz.component(vector::X));
	volScalarField Uzy (gradUz.component(vector::Y));
	volScalarField Uzz (gradUz.component(vector::Z));

	volScalarField SgT
	(
	    IOobject
	    (
		"SgT",
		runTime.timeName(),
		mesh,
		IOobject::NO_READ,
		IOobject::AUTO_WRITE
	    ),
	    (lamda*((fvc::grad(forCalT))&(fvc::grad(forCalT))))/(forCalT*forCalT)  
	);	

	volScalarField SgP
	(
	    IOobject
	    (
		"SgP",
		runTime.timeName(),
		mesh,
		IOobject::NO_READ,
		IOobject::AUTO_WRITE
	    ),
	    (2*mu/forCalT)*(2*(Uxx*Uxx+Uyy*Uyy+Uzz*Uzz)
	    +((Uxy+Uyx)*(Uxy+Uyx)
        +(Uxz+Uzx)*(Uxz+Uzx)
        +(Uyz+Uzy)*(Uyz+Uzy)))
	);	

	volScalarField SgRate
	(
	    IOobject
	    (
		"SgRate",
		runTime.timeName(),
		mesh,
		IOobject::NO_READ,
		IOobject::AUTO_WRITE
	    ),
	    SgT+SgP
	);	

        runTime.write();
    }

