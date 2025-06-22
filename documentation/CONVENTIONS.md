# Rules

This file contains all the rules used in this project.

## GitHub

This section contains all the rules related to the usage of GitHub.

### <i>Commits</i>

This subsection contains all the rules related to the commits on GitHub.

#### <u>Commit Format</u>

Here we describe the used format for all the potential commits you may find on this repository.

All the commits on this repository will have the exact same structure. 

The first element will the be **Commit Message** and it will be made of a **Commit Type** and a **Commit Description**. 

The **Commit Type** will consistently be one among the ones described below. The **Commit Description** will be in plain English, start with a capital letter and end with a period. 

If the commit is related to an issue, the **Commit Description** will end with a reference to that issue. For exemple if the commit is related to the issue **1** then the **Commit Description** will end with **#1**. Finally the **Commit Description** will be written with the present tense.

The second element will be the **Commit Body**. There are no special rules for this element apart from the fact that it should be written again in plain English, start with a capital letter and end with a period. Besides, this element will not be mandatory.

#### <u>Commit Types</u>

Here we decribe all the potential commit types you may find on this repository.

- **[DIVERS]**: Used if your commit do not fit into the next types. You should avoid using this.
- **[DOCUMENTATION]**: Used if your commit change the documentation.
- **[FEATURES]**: Used if your commit implement a new feature.
- **[FIXES]**: Used if your commit fixes something not working as expected.
- **[INITIAL]**: Used for the absolute first commit of the repository.
- **[PERFORMANCES]**: Used if your commit improves the performances of the code.
- **[STYLES]**: Used if your commit changes the style of the code.
- **[TESTS]**: Used if your commit implement tests.

#### <u>Commit Examples</u>

Here we give good and bad examples regarding the established rules.

Good examples:

- ✔️ **[INITIAL]: First commit of the repository.** 
- ✔️ **[DOCUMENTATION]: Implement the documentation for the used conventions. #1**
- ✔️ **[FEATURES]: Implement the most optimal print function. #2**
- ✔️ **[DIVERS]: Modify the logo of the repository.**

Bad examples:

- ✖️ **[FEAT]: Did a new cool feature for matrix multiplication.**
- ✖️ **Random commit.**
- ✖️ **[Feat]: implement scaling of vectors**
- ✖️ **[FEATURES]: Implemented the most optimal print function. #2**

## Code Style

This section contains all the rules related to the code.

### <i>Structure</i>

This subsection contains all the rules related the structure of the code.

The first rule is that each line of code will not contain more than a hundred characters.

### <i>Comments</i>

This subsection contains all the rules related the comments inside of the code.

There will be two types of comment: the **Multiple Lines Comment** and the **Single Line Comment**.

#### <u>Multiple Lines Comment</u>

This comment will be written inside a block with a specific aesthetic and may exist on multiple lines. Here is the template:

```
/*/---------------------\*\
|                         |
| Multiple Lines Comment. |
|                         |
\*\---------------------/*/
```

The block will match the exact size of the comment.

#### <u>Single Line Comment</u>

This comment will start with a specific and stylish set of characters and exist on one single line. Here is the template:

```
//!\\ Single Line Comment.
```
