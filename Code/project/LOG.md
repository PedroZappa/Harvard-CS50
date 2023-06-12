# [Final Project](/README.md): ...

## `Table o'Contents`

* [Preliminary Questions](#preliminary-questions)
* [Milestones/Goals](#milestones-goals)
* [How to Submit](#how-to-submit)

___

## [Preliminary Questions](#table-ocontents)

* What will your software `do`? What `features` will it have? How will it be `executed`?

* What `new skills` will you need to acquire? What `topics` will you need to `research`?

* In the world of software, most everything takes longer to implement than you expect. And so it’s not uncommon to accomplish less in a fixed amount of time than you hope. What might you consider to be a `good outcome` for your project? A `better outcome`? The `best outcome`?

___

## [Milestones/Goals](#table-ocontents)

...

___

## [How to Submit](#table-ocontents)

### `Step 1`

*Create a short video (that’s no more than 3 minutes in length) in which you present your project to the world, as with slides, screenshots, voiceover, and/or live action.

* Your video should somehow include your `project’s title`, your `name`, your `city` and `country`, and any `other details` that you’d like to convey to viewers.

* See [this](howtogeek.com/205742/how-to-record-your-windows-mac-linux-android-or-ios-screen) for tips on how to make a “`screencast`,” though you’re welcome to use an actual camera. Upload your video to YouTube (or, if blocked in your country, a similar site) and take note of its URL; it’s fine to flag it as “unlisted,” but don’t flag it as “private.”

Submit this [form](https://forms.cs50.io/0f486eda-c304-4715-99e3-72bb1058712d)!

___

## Defining the Project (`Software Development Document`)

> A speech-2-text web application powered by Flask.
>
> The application takes live audio input,
recognizes human speech, identifies the language spoken,
and outputs the words spoken to the user.
>
>( Extra Feature: Upgrade to speech-2-image Generate an image from the generated text with Stable Diffusion ).

___

## [`SDD Outline`](https://www.devteam.space/blog/best-software-design-document-templates/) _`[DevTeam]`_

### `Step 1`: Introduction to the SDD including System Overview

`TalkSee`: A speech-2-text web application.

The application takes live audio input, recognizes human speech, identifies the language spoken, and outputs text to the user.

( Extra Goal: Upgrade to speech-2-image by generating an image with from the output text )

### `Step 2`: Software Design considerations including metrics and the user interface design

* Assumptions and Dependencies
* Constraints
* Goals and Guidelines
* Approaches and Methods

### `Step 3`: Decisions that you had to make while choosing the system architecture pattern

* Scalability
* Maintainability
* Availability
* Reliability
* Testability

### `Step 4`: Details concerning the chosen system architecture pattern

* Layered architecture
* Event-driven architecture
* Microkernel architecture
* Micro-services architecture
* Space-based architecture

### `Step 5`: Explanations for the design-related choices

* Infrastructure-related choices, e.g., whether to use a cloud computing platform;
* The kind of cloud computing delivery model to use, e.g., public, private, or hybrid cloud;
* The choice of the technology stack, e.g., MEAN stack (MongoDB-Express.js-Angular.js-Node.js);
* The choice of libraries like jQuery;
* Coding standards and guidelines;
* The choice of application security model;
* The choice of testing frameworks and tools to use;
* The granularity of your requirements traceability matrix;
* The plans for establishing an effective “Continuous Integration” (CI)/”Continuous Delivery” (CD) pipeline;
* Planning the testing and deployment of the application;
* The choice of DevOps tools;
* The choice of external APIs if applicable;
* Planning the maintenance of the software.

### `Step 6`: Detailed system design

* The design of each component and module;
* Relevant details of each file;
* How the proposed system delivers its stated functionality;
* The dependencies between different programs;
* Inputs to each program and their outputs;
* The business logic and validation rules for each functionality;
* The resources used by each component or module;
* The tasks performed by each component and the associated user interactions;
* Constraints and assumptions at a subsystem level.