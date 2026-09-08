# DECISIONS

> The team's memory of *why* approaches were selected or rejected.
> The team should never lose track of why a decision was made.

## Convention

Name files like:

```text
DECISION_001_PROJECT_SELECTION.md
DECISION_002_IDEA2_APPROACH.md
DECISION_003_MVP_SCOPE.md
```

Number sequentially. Use a short, descriptive suffix.

## Template

```markdown
# DECISION_XXX — Title

- **Date:** YYYY-MM-DD
- **Status:** Decided / Proposed / Superseded

## Decision
(What was decided — one or two sentences.)

## Context
(Why this decision was needed. What problem were we solving?)

## Options Considered
(Every real option that was discussed, with a one-line description each.)

## Why This Decision
(The reasoning. What evidence or analysis drove the choice?)

## Consequences
(What this decision means going forward. What it enables, what it rules out, what follow-ups it creates.)
```

## Rules

- **Record decisions when they're made** — not later from memory.
- **One decision per file.**
- **Never rewrite history** — if a decision is reversed, mark the old record `Superseded` and create a new record that references it.
- Link decisions from meeting notes and project READMEs where relevant.

## Records

| # | Decision | Date | Status |
|---|---|---|---|
| [DECISION_001](./DECISION_001_PROJECT_SELECTION.md) | Project selection: SIH26025 + SIH26050 active; SIH26178 set aside | 2026-09-08 | Decided |