# REPO_WORKFLOW

> How work flows through the repository — from idea to pitch.

## The Lifecycle

```text
Research
   ↓
Discussion
   ↓
Decision
   ↓
Documentation
   ↓
Implementation
   ↓
Testing
```

## Where Each Stage Lives

### 1. Research
- **Where:** your project's research folders — `01_IDEA_1_MINE_SUBSIDENCE/WORKSPACE/` or `02_IDEA_2_HIGH_ALTITUDE_ANTI_DRONE/WORKSPACE/`.
- **What:** domain research, existing solutions, technical papers, competitive intelligence.
- **Rule:** document sources. Don't delete research — archive it.

### 2. Discussion
- **Where:** `00_TEAM_WORKSPACE/MEETING_NOTES/` (meeting notes) and/or GitHub issues/discussions.
- **What:** comparing approaches, debating trade-offs, aligning the team.
- **Rule:** capture the discussion outcome in the meeting note.

### 3. Decision
- **Where:** `00_TEAM_WORKSPACE/DECISIONS/DECISION_XXX_...md`.
- **What:** the chosen approach, options considered, why, consequences.
- **Rule:** record decisions when they're made. Never lose track of *why*.

### 4. Documentation
- **Where:** the project's design folders — `01_.../WORKSPACE/`, `02_.../WORKSPACE/`.
- **What:** architecture, technical design, hardware plans, data pipelines.
- **Rule:** documentation reflects decisions; update it when decisions change.

### 5. Implementation
- **Where:** the project's build folders — `01_.../WORKSPACE/`, `02_.../WORKSPACE/` (subfolders created by each squad when build begins). Shared code goes in `03_SHARED_TECH/`.
- **What:** firmware, backend, ML, dashboards, hardware assembly.
- **Rule:** code lives with its project; shared infrastructure lives in `03_SHARED_TECH/`.

### 6. Testing
- **Where:** `01_.../WORKSPACE/`, `02_.../WORKSPACE/`.
- **What:** test plans, validation results, failure-mode analysis, demo scripts.
- **Rule:** record what was tested and what passed/failed.

### 7. Pitch
- **Where:** `01_.../WORKSPACE/`, `02_.../WORKSPACE/`.
- **What:** pitch decks, demo scripts, judge Q&A prep.
- **Rule:** the pitch must trace back to documented research and decisions.

## Current Phase

We are in **Research → Discussion** for both projects (Planning & Deep Research phase). See [`00_CURRENT_STATUS.md`](../00_CURRENT_STATUS.md).

## Quick Decision Flow

```
New idea / approach
   ↓
Research it (project research folder)
   ↓
Discuss with squad/team (meeting note)
   ↓
Decide (DECISIONS/DECISION_XXX)
   ↓
Document (project design folder)
   ↓
Implement (project build folder)
   ↓
Test (project testing folder)
```