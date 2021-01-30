import {
    Entity,
    Column,
    PrimaryGeneratedColumn,
    OneToOne,
    JoinColumn,
    OneToMany,
} from 'typeorm'
import { Review } from './Review'
import { ProfileImage } from './ProfileImage'

@Entity()
export class User {
    @PrimaryGeneratedColumn()
    id: number

    @Column()
    firstName: string

    @Column()
    lastName: string

    @Column()
    username: string

    @Column()
    emailAddress: string

    @Column()
    dateCreated: Date

    @Column()
    hashedPassword: string

    // // Each user can have only one profile Image
    // @OneToOne(() => ProfileImage)
    // @JoinColumn()
    // profileImage: ProfileImage

    // typeORM handles the creation of tables inbetween two tables in order to get multiple items available on another table.
    @OneToMany(() => Review, (review) => review.user)
    reviews: Review[]
}

/*
TO EXPAND ON THIS ENTITY:
- We could store a security question and answer here on the db in case the user want to change their password.
*/
