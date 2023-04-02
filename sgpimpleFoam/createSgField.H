volScalarField SgT
	(
	    IOobject
	    (
		"SgT",
		runTime.timeName(),
		mesh,
		IOobject::MUST_READ,
		IOobject::AUTO_WRITE
	    ),
        mesh
    );
    
    	volScalarField SgP
	(
	    IOobject
	    (
		"SgP",
		runTime.timeName(),
		mesh,
		IOobject::MUST_READ,
		IOobject::AUTO_WRITE
	    ),
        mesh
    );

    	volScalarField SgRate
	(
	    IOobject
	    (
		"SgRate",
		runTime.timeName(),
		mesh,
		IOobject::MUST_READ,
		IOobject::AUTO_WRITE
	    ),
        mesh
    );

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