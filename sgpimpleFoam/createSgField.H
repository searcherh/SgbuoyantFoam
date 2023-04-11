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

		volScalarField ZERO 
	(
		IOobject
		(
			"ZERO",
			runTime.timeName(),
			mesh,
			IOobject::NO_READ,
			IOobject::NO_WRITE 
		),
		mesh,
		dimensionedScalar("ZERO",dimensionSet(1,-1,-3,-1,0,0,0),0)
	);

		dimensionedScalar Sg = fvc::domainIntegrate(ZERO*runTime.deltaTValue());