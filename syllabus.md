---
layout: page
title: Syllabus
---

## Challenging times 

Students and instructors are all adjusting to the changes and regulations that have been put in place in response to COVID-19. I hope that we will all work together as a community to adapt to these times and this new situation as best as we can. I have tried to add ﬂexibility to our course structure and assignments to accommodate anyone who may now be lacking resources that are normally available. However, if you have suggestions for how we might support your learning in this course during these trying times, please do not hesitate to let us know.

## Survey 

Please fill this online [survey](https://docs.google.com/forms/d/e/1FAIpQLSdxd1rdTGfqHA7eGehUoLmVjeXHruqoR4IjYOeOE8cTdSa2wA/viewform?usp=sf_link).

## Teaching staff

Instructor: Eric Darve, ME, ICME, [darve@stanford.edu](mailto:darve@stanford.edu). Prof. Darve is a Professor in Mechanical Engineering and a faculty member affiliated with ICME.

Teaching assistants:

- Ziyi Yang, PhD candidate in Mechanical Engineering; [zy99@stanford.edu](mailto:zy99@stanford.edu)
- Mojtaba Forghani (postdoc) and Kailai Xu (PhD candidate, ICME) will also be assisting

## Lectures and class material

The class will be structured around the following elements. Most of the material for this class will be accessible from the [class web site](https://ericdarve.github.io/me343-cme216-winter-2021/). Meeting information (zoom link) and grades are posted on [Canvas](https://canvas.stanford.edu/courses/131536).

Most of the lectures will be pre-recorded. The material will be listed on the class web site. It is organized in modules, with videos, slides, reading and homework assignments.

At this time, I am not planning on many live lectures. There are practical difficulties including network bandwidth, connection reliability, and time difference.

To supplement the lectures, we will have a combination of reading and homework assignments. **Reading assignments** are short questions that can be answered by reading the slides and watching the videos. **Homework assignments** will be based primarily on Python and will require some code development and analysis.

The [class web site](https://ericdarve.github.io/me343-cme216-winter-2021/) contains useful books, articles, web links, recorded lectures, etc, that are relevant to this class.

## Forum

To communicate we will post messages using [canvas announcements](https://canvas.stanford.edu/courses/131536/announcements). There is also a **Slack** workspace. You will need to join the workspace for this class.

1. Go to [stanford.enterprise.slack.com](https://stanford.enterprise.slack.com/)
2. Search for `me343-cme216-winter-2021`.
3. Sign in. You should be able to join immediately.

Check the channels in the workspace. 

The URL is: [https://stanford-3kml.stanford.edu](https://stanford-3kml.stanford.edu).

Since the class is taught virtually, it is important to maintain contact with the teaching staff and other students. We encourage you to freely share information, questions, feedback, comments, etc, on Slack in the appropriate channel. Slack is meant to be a flexible and open-ended way to communicate.

It is critical that you send feedback about the class to the teaching staff. It could be some comments, things you wish were done differently, or maybe some special difficulty you are facing right now. For feedback, you can use 

- email Eric Darve [darve@stanford.edu](mailto:darve@stanford.edu) or Ziyi Yang [zy99@stanford.edu](mailto:zy99@stanford.edu)
- send a direct message using Slack to Eric Darve or Ziyi Yang
- office hours
- use the anonymous [Google form](https://docs.google.com/forms/d/e/1FAIpQLSeHnFlZqusgedEe-EBAP2OlpS1PK1AgIq-F5qdstCZGcsQnVg/viewform?usp=sf_link). Note that we don't get notified when someone fills the form so it may take time before we see your message. In addition, since this is anonymous, we won't be able to reply to you.

**Rules of conduct.** On the forum, please observe the following code of conduct:

- Be civil, considerate, and courteous to everyone. The forum is meant to be a safe and welcoming space to get help. If your message is not useful to other students, yourself or the instructors, you should probably just delete it.
- Access to the various forums will be revoked without warning if you post an inappropriate, disrespectful, demeaning, or abusive message.

## Office hours

The teaching staff will have office hours. These will be posted on canvas. Look under the [Zoom](https://canvas.stanford.edu/courses/131536/external_tools/5384) tab.

During the zoom office hours, we will use a combination of "Waiting Room", which requires the host to let you in, and "Breakout Rooms", which allow splitting participants into small groups (in this case, we will have each student in their own private "room"). This will allow managing one-on-one discussions with potentially more than one participant in zoom.

## Grading

The grading will be done as follows:

- Final project: 20%
- Reading assignments and short exercises: 30%
- Homework: 50%

We will use [gradescope](https://www.gradescope.com/courses/222525) for homework submission and grading. Search for ME 343 CME 216 Winter 2021. You should be automatically enrolled if you are listed on canvas.

After receiving your grade on gradescope, you are welcome to request a regrade using the gradescope interface. No one is perfect. We strive to grade accurately, fairly, and provide useful feedback to help you, but mistakes do happen. We will be happy to address any concerns you have. However, to help with the logistics, we prefer that you submit your regrade request at most 1 week after the grade has been released.

The final project will be determined by each student. It should be based on one of the topics covered during the quarter, such as SVM, kernel machines, deep learning, TensorFlow, and physics-informed learning. You will have to prepare a 4-page report. For the project you will have to 

- propose a machine learning task in engineering, 
- review briefly the literature and relevant methods for this problem, 
- propose an algorithm and write some Python code to solve the problem, 
- present some benchmark results, 
- comment and discuss the results and conclusions of your work.

## Contents of the class

The tentative contents of the class is shown below. Adjustments will be made depending on how long it takes to cover each topic.

- Introduction to machine learning; [support vector machines](https://scikit-learn.org/stable/modules/svm.html#)
- Deep learning; this will be the bulk of this quarter. We will learn how to use [TensorFlow](https://www.tensorflow.org/). Although very popular as well, we will not cover [PyTorch](https://pytorch.org/). We will discuss various [optimizers](https://www.tensorflow.org/api_docs/python/tf/keras/optimizers) used in deep learning as well as less common ones that are more specific to physics-informed learning, such as [BFGS](https://docs.scipy.org/doc/scipy/reference/tutorial/optimize.html#broyden-fletcher-goldfarb-shanno-algorithm-method-bfgs) and [trust-region methods](https://docs.scipy.org/doc/scipy/reference/tutorial/optimize.html).
- Physics-informed learning. We will discuss how deep neural networks can be used to solve partial differential equations. This topic is specific to engineering applications. This will be based on two frameworks: [DeepXDE](https://github.com/lululxvi/deepxde) developed by Lu Lu from Prof. Karniadakis' group, and [ADCME](https://github.com/kailaix/ADCME.jl) ([wiki page](https://kailaix.github.io/ADCME.jl/dev/)) developed by Kailai Xu from Prof. Darve' group.
- If time allows, we will briefly discuss generative deep networks. This has been a very useful tool in engineering to model stochastic variables and uncertainty.

Although TensorFlow can be used with many languages, we will focus on the standard interface using Python. Knowing Python is a pre-requisite for this class.

## Pre-requisites

The main pre-requisite is Python, which will be used for most of the homework assignments and for demonstrating the algorithms in class. We will use TensorFlow and Keras to learn about deep learning. See the [Python setup guide](Python Setup Guide) for information on how to install Python.

You should also know basic methods in optimization such as gradient descent to minimize a function. 

Towards the end, we will discuss numerical solutions of partial differential equations (PDE) for example with the finite-difference method. But only the basics of PDE solvers are required and we will give you pointers if you have not seen these methods previously. 

We expect basic knowledge of probability and statistics.

## What you can expect from me 

I am here to guide your learning and will challenge you to actively engage in the learning process through class activities, assignments, and more. I will strive for an inclusive and collaborative classroom and welcome any suggestions for improvement. I will do my best to give you the tools, feedback, and support to succeed, so let me know if I can do anything more. Learning is a never-ending process, so I hope to motivate students to seek out more information on topics we don't have time to cover. I highly encourage everyone to visit me in office hours or to set up a meeting, even if you don't feel that you have questions. I want to get to know you and support you in this learning experience! The best way to reach me is by email/Slack (see contact information) and you can expect me to respond within 24 hours (Monday-Friday).

## What I expect from you 

It can be easy to get distracted in a virtual learning environment and during online meetings. So, I ask that you try as best as you can to remain focused and engaged in the class material. I expect you to be proactive and take an active role in your learning by following attentively our lectures and being ready to collaborate with your classmates. Moreover, online settings can often feel anonymous and less personal, sometimes making it easier to misinterpret comments or to share thoughts with less filtering. Keep in mind that each member of this class has different ideas and perspectives that will enrich the experience for us all. I expect all of us to speak and listen with compassion and not make assumptions about others. Never hesitate to email me, join me in my virtual office hours, or set up a meeting. This class should challenge you, but I believe everyone has the ability to succeed with some effort.

## Respect for diversity

It is my intent that students from all diverse backgrounds, perspectives, and situations be well served by this course, that students' learning needs be addressed both in and out of class, and that the diversity that students bring to this class be viewed as a resource, strength and benefit. It is my intent to present materials and activities that are respectful of diversity, which may include but not limited to: gender, sexuality, disability, age, socioeconomic status, ethnicity, race, religion, political affiliation, culture, and so on. I acknowledge that there is likely to be a diversity of access to resources among students and plan to support all of you as best as I can. Please let me know ways to improve the effectiveness of the course for you personally or for other students or student groups. In addition, if any of our class meetings conflict with your religious events, please let me know so that we can make arrangements for you.

All people have the right to be addressed and referred to in accordance with their personal identity. In this class, we will have the chance to indicate the name that we prefer to be called  (see the [Survey](https://docs.google.com/forms/d/e/1FAIpQLSdxd1rdTGfqHA7eGehUoLmVjeXHruqoR4IjYOeOE8cTdSa2wA/viewform?usp=sf_link)) and, if we choose, to identify pronouns with which we would like to be addressed. I will do my best to address and refer to all students accordingly and support classmates in doing so as well.

## Support services

The COVID-19 pandemic is a stressful time for us all. In addition, you may experience a range of other challenges that can cause barriers to learning, such as strained relationships, increased anxiety, alcohol/drug problems, feeling down, difficulty concentrating and/or lack of motivation. These mental health concerns or stressful events may lead to diminished academic performance or reduce your ability to participate in daily life. Stanford is committed to advancing the mental health and well-being of its students. If you or someone you know is feeling overwhelmed, depressed, and/or in need of support, services are available. 

To learn more about the broad range of confidential mental health services available on campus, please see:

    https://vaden.stanford.edu/caps-and-wellness/counseling-and-psychological-services-caps

**We hope you will enjoy this class and find it useful!**

## Students with Documented Disabilities

Students who may need an academic accommodation based on the impact of a disability must initiate the request with the Office of Accessible Education (OAE). Professional staff will evaluate the request, review appropriate medical documentation, recommend reasonable accommodations, and prepare an Accommodation Letter for faculty dated in the current quarter in which the request is being made. The letter will indicate how long it is to be in effect. Students should contact the OAE as soon as possible since timely notice is needed to coordinate accommodations. 

The OAE is located at 563 Salvatierra Walk.

Phone: 723-1066

URL: [oae.stanford.edu](https://oae.stanford.edu)

## Honor Code and Office of Community Standards

We take the honor code very seriously. The honor code is Stanford's statement on academic integrity first written by Stanford students in 1921. It articulates university expectations of students and faculty in establishing and maintaining the highest standards in academic work. It is agreed to by every student who enrolls and by every instructor who accepts appointment at Stanford. The Honor Code states:

1. The Honor Code is an undertaking of the students, individually and collectively

    (a) that they will not give or receive aid in examinations; that they will not give or receive unpermitted aid in class work, in the preparation of reports, or in any other work that is to be used by the instructor as the basis of grading;

    (b) that they will do their share and take an active part in seeing to it that others as well as themselves uphold the spirit and letter of the Honor Code.

2. The faculty on its part manifests its confidence in the honor of its students by refraining from proctoring examinations and from taking unusual and unreasonable precautions to prevent the forms of dishonesty mentioned above. The faculty will also avoid, as far as practicable, academic procedures that create temptations to violate the Honor Code.
3. While the faculty alone has the right and obligation to set academic requirements, the students and faculty will work together to establish optimal conditions for honorable academic work.

Note that the student who lets others copy his work is as guilty as those who copy. Violations include at least the following circumstances: copying material from another student, copying previous year solution sets, copying solutions found using Google, copying solutions found on the internet. You will be automatically reported without a warning if a violation is suspected. The Office of Community Standards is in charge of determining whether a violation actually occurred or not.

Please do not post any material from this class online. This will encourage honor code violation, and penalize other students. This is also a violation of copyright.

If found guilty of a violation, your grade will be automatically lowered by at least one letter grade, and the instructor may decide to give you a "No Pass" or "No Credit" grade. The standard sanction from OCS for a first offense includes a one-quarter suspension from the University and 40 hours of community service. For multiple violations (e.g., cheating more than once in the same course), the standard sanction is a three-quarter suspension and 40 or more hours of community service.

[Honor Code statement and information](https://communitystandards.stanford.edu/policies-and-guidance/honor-code)